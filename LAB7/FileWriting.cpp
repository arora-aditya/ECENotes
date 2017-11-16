//
//  FileWriting.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-11-08.
//
//  reject non csv file
//  given filename foo, open foo.csv

//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <fstream>
#include <math.h>

//////////////////////////////////////////////////////////////
//
// local #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
#endif

//////////////////////////////////////////////////////////////
//
// struct definitions
//
using namespace std;
#ifndef MARMOSET_TESTING
struct Student{
	int studentID;
	int grade;

	Student(){
		studentID = 0;
		grade = -1;
	}
};

struct Dataset{
	int numStudents;
	Student* students;

	Dataset(){
		numStudents = 0;
		students = NULL;
	}
};

struct Rejects {
	int numRejects;
	int* rejects;

	Rejects(){
		numRejects = 0;
		rejects = NULL;
	}
};

struct Mode{
	int numModes;
	int* modes;
};

struct Statistics{
	int   minimum;
	float average;
	int   maximum;
	float popStdDev;
	float smplStdDev;
	Mode  mode;
	int   histogram[10];
};

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
//
int readCSV(const char filename[],const int minAcceptableID, const int maxAcceptableID,Dataset& data,	Rejects& rejects);

int computeStatistics(Dataset& data, Statistics& stats);

int writeCSV(const char filename[], const Statistics& stats);

//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS
//

int strle(const char str[]){
	int i;
	for(i = 0; str[i] != '\0'; i++);
	return i;
}

void ModeAppend(int s, Mode& M){
	int* k = new int [M.numModes + 1];
	int i;
	for(i = 0; i < M.numModes; i++){
		k[i] = *(M.modes + i);
	}
	k[i] = s;
	delete M.modes;
	M.modes = k;
	M.numModes++;
}

bool RejectsAppend(int s, Rejects& R){
	int* k = new int [R.numRejects + 1];
	int i;
	for(i = 0; i < R.numRejects; i++){
		k[i] = *(R.rejects + i);
	}
	k[i] = s;
	delete R.rejects;
	R.rejects = k;
	R.numRejects++;
	if(R.numRejects > 10){
		return false;
	}
	return true;
}

void DataAppend(Student S, Dataset& data){
	Student* k = new Student [data.numStudents + 1];
	int i;
	for(i = 0; i < data.numStudents; i++){
		k[i] = *(data.students + i);
	}
	k[i] = S;
	delete data.students;
	data.students = k;
	data.numStudents++;
}

bool stringToInt(const char input[], int* value) {
    int result = 0;
    int sign = 1;
    int i = 0;
    while(input[i] == ' ' || input[i] == '\t') {
        i++;
    }
    if(input[i] == '-' || input[i] == '+') sign = (input[i++] == '-')? -1 : 1;
    while('0' <= input[i] && input[i] <= '9') {
        result = result*10 + (input[i++]-'0');
				if(result*sign >= 2147483647){
					return false;
				}
		    if(result*sign <= -2147483648){
					return false;
				}
    }
		int len = strle(input);
		while(i < len){
			if('0' <= input[i] && input[i] <= '9'){
				return false;
			}
			i++;
		}
    *value = sign * result;
		return true;

}

int parseLine(const char * line, Student& s) {
    int i = 0;
		char _id[] = "                                                                                                                                                                        ";
		char _mark[] = "                                                                                                                                                ";
    while(line[i] != ',' && i < 100) {
        _id[i] = line[i];
        i++;
    }
    int lenId = i;
    _id[i++] = '\0';
		if(line[i] == '\0'){
            return 10;
    }
    for(; line[i] != '\0' && i <100; i++) {
        _mark[i - lenId - 1] = line[i];
    }
		bool flag = false, commaFlag = true, multipleCommaFlag = false;
		int lenLine = strle(line);
		int j =0;
		for(int j = 0; j < lenLine && j < 100; j++){
			// cout<<j<<endl;
			if(line[j] != ' '){
				flag = true;
			}
			if(line[j] == ','){
				if(!commaFlag){
					multipleCommaFlag = true;
				}
				commaFlag = false;
			}
		}
		if(!flag){
			return 3;
		}
		if(commaFlag){
			return 4;
		}
		if(multipleCommaFlag){
			return 5;
		}
		if(!stringToInt(_id, &s.studentID) || !stringToInt(_mark, &s.grade)){
			return 0;
		}
		else{
			// cout<<s.studentID<<'\t'<<s.grade<<endl;
			return 1;
		}
		// cout<<(!stringToInt(_id, &s.studentID) || !stringToInt(_mark, &s.grade))<<endl;
}


int readCSV(const char fileName[], const int minAcceptableID, const int maxAcceptableID, Dataset& data, Rejects& rejects){

	rejects.numRejects = 0;
	rejects.rejects = NULL;
	data.numStudents = 0;
	data.students = NULL;

	if(minAcceptableID >= maxAcceptableID){
		return -13;
	}
	const int maxLineLength = 100;
	char line[maxLineLength];
	ifstream infile;            // declare the file object
	int lenFileName = strle(fileName);
	char fileNameFinal[1000] = "";
	for(int i = 0; i < lenFileName; i++){
		fileNameFinal[i] = fileName[i];
	}

	if((fileName[lenFileName-1] != 'v' && fileName[lenFileName-2] != 's' && fileName[lenFileName-3] != 'c') && fileName[lenFileName-4] == '.') {
		return -20;
	}

	if(fileName[lenFileName-1] != 'v' || fileName[lenFileName-2] != 's' || fileName[lenFileName-3] != 'c' || fileName[lenFileName-4] != '.') {
		for(int i = 0; i < lenFileName; i++){
			fileNameFinal[i] = fileName[i];
		}
		fileNameFinal[lenFileName + 4] = '\0';
		fileNameFinal[lenFileName + 3] = 'v';
		fileNameFinal[lenFileName + 2] = 's';
		fileNameFinal[lenFileName + 1] = 'c';
		fileNameFinal[lenFileName + 0] = '.';
	}
	infile.open(fileNameFinal);      // open the file
	if (!infile.is_open()) return -15;                // Unable to open file
	bool done = false;
	int fileLineNumber = 0;
	while (!done) {             // Read from file
		++fileLineNumber;
		if (!infile.getline(line, maxLineLength)) { // Get next line
				if (infile.eof()) {                       // End of file
						done = true;
						break;
				}
				else {                  // Some error reading file
						return -10;
				}
		}
		Student S;
		S.studentID = 0;
		S.grade = -1;
		int t = parseLine(line, S);
		// cout<<t<<'\t'<<S.studentID<<'\t'<<S.grade<<endl;
		if(t >= 3){
			if(!RejectsAppend(fileLineNumber, rejects)){
				return -35;
			}
		}
		else{
			if(S.studentID >= minAcceptableID && S.studentID <= maxAcceptableID && S.grade <= 100 && S.grade >= 0){
				DataAppend(S, data);
			}
			else{
				if(!RejectsAppend(fileLineNumber, rejects)){
					return -35;
				}
			}
		}
	}
	return rejects.numRejects;
}


int minimum(const int dataset[], const int size) {
  int mini = 2147483647;
  int n = size;
  int i = 0;
  while(i < n){
    if(mini >  dataset[i])
    {
      mini = dataset[i];
    }
    i++;
  }
  return mini;
}

float average(const int dataset[], const int size) {
  float sum = 0;
  int n = size;
  int i = 0;
  while(i < n){
    sum += dataset[i];
    i++;
  }
  float avg = sum/n;
  return avg;
}

int maximum(const int dataset[], const int size) {
  int max = -2147483648;
  int n = size;
  int i = 0;
  while(i < n){
    if(max <  dataset[i])
    {
      max =  dataset[i];
    }
    i++;
  }
  return max;
}

float popStdDev(const int dataset[], const int size) {
  float avg = average(dataset, size);
  float deviation = 0;
  int i = 0;
  int n = size;
  while(i < n){
    deviation += pow((dataset[i]-avg),2);
    i++;
  }
  return sqrt(deviation/n);
}

float smplStdDev(const int dataset[], const int size) {
  if(size <= 1){
    return +INFINITY;
  }
  float avg = average(dataset, size);
  float deviation = 0;
  int i = 0;
  int n = size;
  while(i < n){
    deviation += pow((dataset[i]-avg),2);
    i++;
  }
  return sqrt(deviation/(n-1));
}

// Return minimum index
int minIndex(int a[], int i, int j) {
    if (i == j)
        return i;

    // Find minimum of remaining elements
    int k = minIndex(a, i + 1, j);

    // Return minimum of current and remaining.
    return (a[i] < a[k])? i : k;
}

// Recursive selection sort. n is size of a[] and index
// is index of starting element.
void selection(int a[], int n, int index = 0) {
    // Return when starting and size are same
    if (index == n)
       return;

    // calling minimum index function for minimum index
    int k = minIndex(a, index, n-1);

    // Swapping when index nd minimum index are not same
    if (k != index)
       swap(a[k], a[index]);

    // Recursively calling selection sort function
    selection(a, n, index + 1);
}

bool sort(int dataset[], const int size) {
    selection(dataset, size);
    return true;
}

void mode(const int dataset[], const int size, Mode &mode) {
		mode.numModes = 0;
		mode.modes = NULL;
    int copy[size], uniqueDataset[size], count[size];
    for(int i = 0; i < size; i++){
        copy[i] = dataset[i];
    }
    sort(copy, size);
    int j = 0;
    uniqueDataset[j] = copy[0];
    count[j] = 0;
    int maxCount = -2147483648;
    for(int i = 0; i < size; i++){
        if(uniqueDataset[j] != copy[i]){
            j += 1;
            uniqueDataset[j] = copy[i];
            count[j] = 0;
        }
        count[j] += 1;
        if(maxCount < count[j]){
            maxCount = count[j];
        }
    }
    // for(int i = 0; i < j+1; i++){
    //     cout<<count[i]<<"  "<<uniqueDataset[i]<<endl;
    // }
    for(int i = 0; i < j + 1; i++){
        if(maxCount == count[i]){
            ModeAppend(uniqueDataset[i], mode);;
        }
    }
}

void histogram(int dataset[], int size, int histogram[10]) {
  for(int i = 0; i < size; i++){
    histogram[(int) dataset[i]/10] += 1;
	}
}


int computeStatistics(Dataset& data, Statistics& stats){
	stats.minimum = 2147483647;
	stats.maximum = -214748364;
	for(int i = 0; i < 10; i++) {
			stats.histogram[i] = 0;
	}
	stats.average = stats.popStdDev = stats.smplStdDev = -0;
	if(data.numStudents == 0){
		stats.maximum = 0;
		stats.minimum = 0;
		return -1;
	}
	int dataset[data.numStudents];
	for(int i = 0; i < data.numStudents; i++){
		dataset[i] = (data.students + i)->grade;
	}
	mode(dataset, data.numStudents, stats.mode);
	stats.minimum = minimum(dataset, data.numStudents);
	stats.maximum = maximum(dataset, data.numStudents);
	stats.average = average(dataset, data.numStudents);
	stats.popStdDev = popStdDev(dataset, data.numStudents);
	stats.smplStdDev = smplStdDev(dataset, data.numStudents);
	histogram(dataset, data.numStudents, stats.histogram);
	return 0;
}

int writeCSV(const char filename[], const Statistics& stats) {
	ofstream outfile;            // declare the file object
	int lenFileName = strle(filename);
	char fileNameFinal[100] = "";
	if(filename[lenFileName-1] != 'v' || filename[lenFileName-1] != 's' || filename[lenFileName-1] != 'c' || filename[lenFileName-1] != '.') {
		if(filename[lenFileName-1] == 'v' && filename[lenFileName-2] == 's' && filename[lenFileName-3] == 'c' && filename[lenFileName-4] == '.'){
			lenFileName -= 4;
		}
		for(int i = 0; i < lenFileName; i++){
			fileNameFinal[i] = filename[i];
		}
		fileNameFinal[lenFileName + 5] = '\0';
		fileNameFinal[lenFileName + 4] = 't';
		fileNameFinal[lenFileName + 3] = 'a';
		fileNameFinal[lenFileName + 2] = 't';
		fileNameFinal[lenFileName + 1] = 's';
		fileNameFinal[lenFileName + 0] = '.';
	}
	outfile.open(fileNameFinal);      // open the file
	if (!outfile.is_open()) return -1;                // Unable to open file...
	outfile << "Minimum: " << stats.minimum << std::endl;
	outfile << "Average: " << stats.average << std::endl;
	outfile << "Maximum: " << stats.maximum << std::endl;
	outfile << "Population Standard Deviation: " << stats.popStdDev << std::endl;
	outfile << "Sample Standard Deviation: " << stats.smplStdDev << std::endl;

	outfile << "Modes: ";
	for (unsigned char i = 0; i < stats.mode.numModes; i++)
	{	outfile << stats.mode.modes[i];
		if(i != stats.mode.numModes - 1){
			outfile<<", ";
		}
		else{
			outfile << std::endl;
		}
	}
	outfile << "Histogram:"<<endl;
	for (unsigned char i = 0; i < 10; i++)
	{
		outfile <<"["<< (i*10) << "-" << ((((i+1)*10) - 1) + i/9) << "]: " << stats.histogram[i] << std::endl;
	}
	outfile.close();
	return 0;
}
//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {

	// Some test driver code here ....
	int minAcceptableID = 1000;
	int maxAcceptableID = 10000;

	Dataset data;
	Rejects rejects;
	Statistics stats;

	// std::cout << std::endl << "Implement some more appropriate tests in main()" << std::endl << std::endl;
	int k = readCSV(argv[1], minAcceptableID, maxAcceptableID, data, rejects);
	if(k < 0)
	{
		std::cout << ".csv file could not be read" << std::endl;
	}
	cout<<rejects.numRejects<<endl;
	cout<<k<<endl;
	// cout<<*(rejects.rejects)<<endl;
	if (computeStatistics(data, stats) < 0)
	{
		std::cout << "Stats could not be computed" << std::endl;
	}

	if (writeCSV(argv[1], stats) < 0)
	{
		std::cout << ".stat file could not be written" << std::endl;
	}

	std::cout << "Minimum: " << stats.minimum << std::endl;
	std::cout << "Average: " << stats.average << std::endl;
	std::cout << "Maximum: " << stats.maximum << std::endl;
	std::cout << "Population Standard Deviation: " << stats.popStdDev << std::endl;
	std::cout << "Sample Standard Deviation: " << stats.smplStdDev << std::endl;

	std::cout << "Modes: ";
	for (unsigned char i = 0; i < stats.mode.numModes; i++)
	{
		std::cout<< stats.mode.modes[i];
		if(i != stats.mode.numModes - 1){
			std::cout<<", ";
		}
	}
	std::cout << endl;
	std::cout << "Histogram:"<<endl;
	for (unsigned char i = 0; i < 10; i++)
	{
		std::cout <<"["<< (i*10) << "-" << ((((i+1)*10) - 1) + i/9) << "]: " << stats.histogram[i] << std::endl;
	}

	return 0;
}

#endif
