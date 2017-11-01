//
//  FileReading.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-10-31.
//
// how to detect end of line?

#include <iostream>
#include <fstream>

using namespace std;

void parseLine(const char line){
    int i = 0;
    while(line[i] != ","){

    }
}

int histogram(const char fileName[], int histogram[10], const int minAcceptableID, const int maxAcceptableID, int *rejects){
    const int maxLineLength = 100;
    char line[maxLineLength];
    ifstream infile;            // declare the file object
    infile.open(fileName);      // open the file
    if (!infile.is_open()) return -1;                // Unable to open file
    bool done = false;
    int fileLineNumber = 0;while (!done) {             // Read from file
        ++fileLineNumber;
        if (!infile.getline(line, maxLineLength)) { // Get next line
            if (infile.eof()) {                       // End of file
                done = true;
            }
            else {                  // Some error reading file
                return -1;
            }
        }
        for(int i = 0; i < maxLineLength; i++){
            cout<<line[i];
        }
        parseLine(line);          // Parse the line// (can use state machine)
        // doHistogramStuff();
    }
}

int main()
{   int histogra[10] = {0,0,0,0,0,0,0,0,0,0};
    int *rejects = new int;
    histogram("test.csv", histogra, 10000, 30000, rejects);
	cout<<"Hello World"<< endl;
	return 0;
}
