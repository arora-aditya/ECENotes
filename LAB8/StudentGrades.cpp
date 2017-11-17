#include <fstream>
#include <math.h>
#include <string.h>
#ifndef MARMOSET_TESTING
#include <iostream>
#endif

using namespace std;
void BubbleSort(int num[], int size) {
      int i, j, flag = 1;    // set flag to 1 to start first pass
      int temp;             // holding variable
      int numLength = size;
      for(i = 1; (i <= numLength) && flag; i++)
     {
          flag = 0;
          for (j=0; j < (numLength -1); j++)
         {
               if (num[j+1] < num[j])      // ascending order simply changes to <
              {
                    temp = num[j];             // swap elements
                    num[j] = num[j+1];
                    num[j+1] = temp;
                    flag = 1;               // indicates that a swap occurred.
               }
          }
     }
     return;   //arrays are passed to functions by address; nothing is returned
}
struct Student{
	int studentID;
	int grade;
	int lineNumber;

	Student(){
		studentID = 0;
		grade = -1;
    lineNumber = -1;
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

struct Rejects {
	int numRejects;
	int* rejects;

	Rejects(){
		numRejects = 0;
		rejects = NULL;
	}

	void print() {
		for(int i = 0; i< numRejects; i++){
			cout<<*(rejects+i)<<'\t';
		}
		cout<<endl;
	}
};
bool RejectsAppend(int s, Rejects& R){
	int* k = new int [R.numRejects + 1];
	int i;
	for(i = 0; i < R.numRejects; i++){
		k[i] = *(R.rejects + i);
	}
	k[i] = s;
	BubbleSort(k,R.numRejects + 1);
	delete R.rejects;
	R.rejects = k;
	R.numRejects++;
	if(R.numRejects > 10){
		return false;
	}
	return true;
}

struct Mode{
	int numModes;
	int* modes;
};
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

int strle(const char str[]){
	int i;
	for(i = 0; str[i] != '\0'; i++);
	return i;
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


class StudentGrades {
public:
  // Supported statistics
  int   minimum();
  float average();
  int   maximum();
  float popStdDev();
  float smplStdDev();
  int   numModes();
  int   mode(const int modeNumber);
  int   histogram(const int bucketNumber);
  int   minIndex(int a[], int i, int j);
  void  selection(int a[], int n, int index = 0);
  bool  sort(int dataset[], const int size);
  // Populating the data and writing out results
  int  readCSV(const char filename[]);
  int  writeStats(const char filename[]);

  // Some supporting functions
  bool validStudentIDs(const int minAcceptableID, const int maxAcceptableID);
  int  numRejects();
  int  reject(const int rejectNumber);

  // Constructor and Destructor
  StudentGrades();
  ~StudentGrades();
:
  Dataset completeDataset;
  Dataset data;
  Mode modes;
  Rejects rejects;
	Rejects illegalRejects;
  int histogramActual[10];
  int minAcceptableID;
  int maxAcceptableID;
	bool dataRead;
	char FileNameFinal[1000];
// It is up to you what you store here
};

StudentGrades::StudentGrades() {
	dataRead = false;
	for(int i = 0; i < 10; i++){
		histogramActual[i] = 0;
	}
}
StudentGrades::~StudentGrades() {
	dataRead = false;
}
int StudentGrades::readCSV(const char fileName[]) {
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
  const int maxLineLength = 100;
	char line[maxLineLength];
	ifstream infile;
	strcpy(FileNameFinal, fileNameFinal);
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
		int t = parseLine(line, S);
		if(t >= 3){
      S.lineNumber = fileLineNumber;
			if(!RejectsAppend(fileLineNumber, illegalRejects)){
				return -35;
			}
		}
		else{
      S.lineNumber = fileLineNumber;
      DataAppend(S, completeDataset);
		}
	}
	dataRead = true;
	return 0;
}

bool StudentGrades::validStudentIDs(const int MinAcceptableID, const int MaxAcceptableID) {
  if(MinAcceptableID >= MaxAcceptableID){
    return false;
  }
  else{
    data.numStudents = 0;
		data.students = NULL;
    rejects.numRejects = illegalRejects.numRejects;
		rejects.rejects = illegalRejects.rejects;
		true;
    minAcceptableID = MinAcceptableID;
    maxAcceptableID = MaxAcceptableID;
    for(int i = 0; i < completeDataset.numStudents; i++) {
      Student S = *(completeDataset.students + i);
      if(S.studentID >= minAcceptableID && S.studentID <= maxAcceptableID && S.grade <= 100 && S.grade >= 0){
				DataAppend(S, data);
			}
    }
    return true;
  }
	dataRead = false;
}

int StudentGrades::minimum(){
  int dataset[1000];
  for(int j = 0; j < 1000; j++){
    dataset[j] = 0;
  }
  for(int i = 0; i < data.numStudents; i++){
		dataset[i] = (data.students + i)->grade;
	}
  int mini = 2147483647;
  int n = data.numStudents;
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

float StudentGrades::average() {
  int dataset[1000];
  for(int j = 0; j < 1000; j++){
    dataset[j] = 0;
  }
  for(int i = 0; i < data.numStudents; i++){
		dataset[i] = (data.students + i)->grade;
	}
  float sum = 0;
  int n = data.numStudents;
  int i = 0;
  while(i < n){
    sum += dataset[i];
    i++;
  }
  float avg = sum/n;
  return avg;
}

int StudentGrades::maximum() {
  int dataset[1000];
  for(int j = 0; j < 1000; j++){
    dataset[j] = 0;
  }
  for(int i = 0; i < data.numStudents; i++){
		dataset[i] = (data.students + i)->grade;
	}
  int max = -2147483648;
  int n = data.numStudents;
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

float StudentGrades::popStdDev() {
  int dataset[1000];
  for(int j = 0; j < 1000; j++){
    dataset[j] = 0;
  }
  for(int i = 0; i < data.numStudents; i++){
		dataset[i] = (data.students + i)->grade;
	}
  float avg = average();
  float deviation = 0;
  int i = 0;
  int n = data.numStudents;
  while(i < n){
    deviation += pow((dataset[i]-avg),2);
    i++;
  }
  return sqrt(deviation/n);
}

float StudentGrades::smplStdDev() {
  int dataset[1000];
  for(int j = 0; j < 1000; j++){
    dataset[j] = 0;
  }
  for(int i = 0; i < data.numStudents; i++){
		dataset[i] = (data.students + i)->grade;
	}
  if(data.numStudents <= 1){
    return +INFINITY;
  }
  float avg = average();
  float deviation = 0;
  int i = 0;
  int n = data.numStudents;
  while(i < n){
    deviation += pow((dataset[i]-avg),2);
    i++;
  }
  return sqrt(deviation/(n-1));
}

int StudentGrades::minIndex(int a[], int i, int j) {
    if (i == j)
        return i;

    // Find minimum of remaining elements
    int k = minIndex(a, i + 1, j);

    // Return minimum of current and remaining.
    return (a[i] < a[k])? i : k;
}

void StudentGrades::selection(int a[], int n, int index) {
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

bool StudentGrades::sort(int dataset[], const int size) {
    selection(dataset, size);
    return true;
}

int StudentGrades::numModes() {
  int dataset[1000];
  for(int j = 0; j < 1000; j++){
    dataset[j] = 0;
  }
  for(int i = 0; i < data.numStudents; i++){
		dataset[i] = (data.students + i)->grade;
	}
  int size = data.numStudents;
		modes.numModes = 0;
		modes.modes = NULL;
    int copy[1000], uniqueDataset[1000], count[1000];
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
    for(int i = 0; i < j + 1; i++){
        if(maxCount == count[i]){
            ModeAppend(uniqueDataset[i], modes);;
        }
    }
    return modes.numModes;
}

int StudentGrades::mode(const int modeNumber) {
	numModes();
  if(!dataRead){
    return 0;
  }
  else if(modeNumber > modes.numModes || modeNumber < 1 || data.numStudents == 0 || completeDataset.numStudents == 0){
    return -1;
  }
  else{
    return *(modes.modes + modeNumber - 1);
  }
}

int StudentGrades::histogram(const int bucketNumber) {
	for(int i = 0; i < 10; i++){
		histogramActual[i] = 0;
	}
  if(bucketNumber > 10 || bucketNumber < 1){
    return -1;
  }
  for(int i = 0; i < data.numStudents; i++){
    histogramActual[(int) (data.students+i)->grade/10] += 1;
	}
  return histogramActual[bucketNumber-1];
}

int StudentGrades::numRejects() {
  return rejects.numRejects;
}

int StudentGrades::reject(const int rejectNumber) {
  if(rejectNumber > rejects.numRejects){
    return -100;
  }
  else{
    return *(rejects.rejects + rejectNumber - 1);
  }
}

int StudentGrades::writeStats(const char filename[]) {
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
  ofstream outfile;            // declare the file object
  outfile.open(fileNameFinal);      // open the file
	if (!outfile.is_open()) return -1;
  outfile << "Minimum: " << minimum() << std::endl;
	outfile << "Average: " << average() << std::endl;
	outfile << "Maximum: " << maximum() << std::endl;
	outfile << "Population Standard Deviation: " << popStdDev() << std::endl;
	outfile << "Sample Standard Deviation: " << smplStdDev() << std::endl;
  outfile << "Modes: ";
  numModes();
	for (unsigned char i = 0; i < modes.numModes; i++)
	{	outfile << mode(i+1);
		if(i != modes.numModes - 1){
			outfile<<", ";
		}
		else{
			outfile << std::endl;
		}
	}
	outfile << "Histogram:"<<endl;
	for (unsigned int i = 0; i < 10; i++)
	{
		outfile <<"["<< (i*10) << "-" << ((((i+1)*10) - 1) + i/9) << "]: " << histogram(i+1) << std::endl;
	}
	outfile.close();
	return 0;
}

int main(const int argc, const char* const argv[]) {
  for(int i = 1; i < argc; i++) {
    int minAcceptableID = 1000;
    int maxAcceptableID = 22229999;
  	StudentGrades S;
    S.readCSV(argv[i]);
    S.validStudentIDs(minAcceptableID, maxAcceptableID);
    S.writeStats(argv[i]);
		int r = S.numRejects();
		for(int i = 0; i< r; i++){
			cout<<S.reject(i+1)<<'\t';
		}
		cout<<endl;
  }
}
