//
//  FileReading.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-10-31.
//
//

#include <iostream>
#include <fstream>

using namespace std;

void stringToInt(const char input[], float* value){
	int result = 0;
    int sign = 1;
	int i = 0;
	if(input[i] == '-' || input[i] == '+') sign = (input[i++] == '-')? -1 : 1;
	while('0' <= input[i] && input[i] <= '9'){
		result = result*10 + (input[i++]-'0');
	}
	if(input[i] != '\0'){
        *value = 0;
	}
	*value = sign * result;
}

void doHistogramStuff(char * id, char * marks, const int minAcceptableID, const int maxAcceptableID, int histogram[10], int * rejects, int LineNumber){
    static int i = 0;
    float idNum = minAcceptableID - 1;
    stringToInt(id, &idNum);
    float marksNum =  -1;
    stringToInt(marks, &marksNum);
    if(idNum >= minAcceptableID && idNum <= maxAcceptableID && marksNum <= 100 && marksNum >= 0){
        histogram[(int) marksNum/10] += 1;
    }
    else{
        rejects[i++] = LineNumber;
    }
}

void parseLine(const char *line, char * id, char * mark){
    int i = 0;
    while(line[i] != ','){
        id[i++] = line[i];
    }
    cout<<endl;
    int lenId = i;
    id[i++] = '\0';
    for(;line[i] != '\0'; i++){
        mark[i - lenId - 1] = line[i];
    }
}

int histogram(const char fileName[], int histogram[10], const int minAcceptableID, const int maxAcceptableID, int *rejects){
    const int maxLineLength = 100;
    char line[maxLineLength];
    ifstream infile;            // declare the file object
    infile.open(fileName);      // open the file
    if (!infile.is_open()) return -1;                // Unable to open file
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
                return -1;
            }
        }
        char id[] = "                        ";
        char mark[] = "                        ";
        parseLine(line, id, mark);          // Parse the line// (can use state machine)
        doHistogramStuff(id, mark, minAcceptableID, maxAcceptableID, histogram, rejects, fileLineNumber);
    }
    return -2;
}

int main()
{   int histogra[10] = {0,0,0,0,0,0,0,0,0,0};
    int *rejects = new int[10];
    histogram("test.csv", histogra, 10000, 30000, rejects);
    for(int i = 0; i < 10; i++){
        cout<<histogra[i]<<"\t";
        cout<<*(rejects + i)<<endl;
    }
	// cout<<"Hello World"<< endl;
	return 0;
}
