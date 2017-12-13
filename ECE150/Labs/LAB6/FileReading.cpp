//
//  FileReading.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-10-31.
//
//

#include <fstream>
#include <limits>

#ifndef MARMOSET_TESTING
#include <iostream>
int maxNumErrors = 10;
using namespace std;
#endif

using namespace std;
int maxNumErrors = 10;
void stringToInt(const char input[], float* value) {
    int result = 0;
    int sign = 1;
    int i = 0;
    while(input[i] == ' ' || input[i] == '\t') {
        i++;
    }
    if(input[i] == '-' || input[i] == '+') sign = (input[i++] == '-')? -1 : 1;
    while('0' <= input[i] && input[i] <= '9') {
        result = result*10 + (input[i++]-'0');
    }
    if(input[i] != '\0' && input[i] != ' ' && input[i] != '\t') {
        *value = std::numeric_limits<float>::quiet_NaN();
    }
    else {
        *value = sign * result;
    }
}

int doHistogramStuff(char * id, char * marks, const int minAcceptableID, const int maxAcceptableID, int histogram[10], int * rejects, int LineNumber, int &retCode) {
    if(minAcceptableID >= maxAcceptableID) {
        return -1;
    }
    float idNum = minAcceptableID - 1;
    stringToInt(id, &idNum);
    float marksNum =  -1;
    stringToInt(marks, &marksNum);
    if(marksNum != marksNum || idNum != idNum) {
        return -1;
    }
    else if(idNum >= minAcceptableID && idNum <= maxAcceptableID && marksNum <= 100 && marksNum >= 0) {
        histogram[(int) marksNum/10] += 1;
    }
    else {
        rejects[retCode++] = LineNumber;
    }
    return 0;
}

void parseLine(const char *line, char * id, char * mark) {
    int i = 0;
    while(line[i] != ',') {
        id[i] = line[i];
        i++;
    }
    int lenId = i;
    id[i++] = '\0';
    for(; line[i] != '\0'; i++) {
        mark[i - lenId - 1] = line[i];
    }
}

int histogram(const char fileName[], int histogram[10], const int minAcceptableID, const int maxAcceptableID, int *& rejects) {
    if(histogram == NULL) {
        return -1;
    }
    for(int i = 0; i < 10; i++) {
        histogram[i] = 0;
    }
    rejects = new int [10];
    int i = 0;
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
        if (doHistogramStuff(id, mark, minAcceptableID, maxAcceptableID, histogram, rejects, fileLineNumber, i) == -1) {
            return -1;
        };
    }
    if(i >= 0 && i <= maxNumErrors) {
        return i;
    }
    else {
        return -1;
    }
}

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {

    // Some test driver code here ....
    if (argc < 2) {

    }
    const int numBuckets = 10;
    const int bucketRange = 100/numBuckets;
    int  buckets[numBuckets];
    int* rejectedRecords;
    int retCode = histogram(argv[1], buckets, 22200000, 22299999, rejectedRecords);
    if (retCode < 0) {
        cout << "Unable to compute histogram." << endl;
    }
    else {
        for (int i = 0; i < numBuckets; ++i)
            if (i != numBuckets-1)
                cout << "Number [" << i*bucketRange << "," << (((i+1)*bucketRange)-1) << "]: " << buckets[i] << endl;
            else
                cout << "Number [" << i*bucketRange << "," << (((i+1)*bucketRange)) << "]: " << buckets[i] << endl;
        if (retCode > 0) {
            cout << "Number of rejected records: " << retCode << endl;
            cout << "Rejected records are:";
            for (int i = 0; i < retCode; ++i)
                cout << " " << rejectedRecords[i];
            cout << endl;
            delete[] rejectedRecords;
        }
    }
    return 0;
}

#endif
