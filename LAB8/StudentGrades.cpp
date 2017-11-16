#include <fstream>
#include <math.h>
#ifndef MARMOSET_TESTING
#include <iostream>
#endif

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

// Populating the data and writing out results
int  readCSV(const char filename[]);
int  writeStats(const char filename[]);

// Some supporting functions
bool validStudentIDs(const int minAcceptableID, const int maxAcceptableID);
int  numRejects();int  reject(const int rejectNumber);

// Constructor and Destructor
StudentGrades();
~StudentGrades();
private:
  int *dataset;
// It is up to you what you store here
};

StudentGrades::StudentGrades(){
  *dataset = NULL;
}

int StudentGrades::minimum(){
  int mini = 2147483647;
  int n = size;
  int i = 0;
  while(i < n){
    if(mini >  *(dataset+i))
    {
      mini = *(dataset+i);
    }
    i++;
  }
  return mini;
}

float StudentGrades::average(const int dataset[], const int size) {
  float sum = 0;
  int n = size;
  int i = 0;
  while(i < n){
    sum += *(dataset+i);
    i++;
  }
  float avg = sum/n;
  return avg;
}

int StudentGrades::maximum(const int dataset[], const int size) {
  int max = -2147483648;
  int n = size;
  int i = 0;
  while(i < n){
    if(max <  *(dataset+i))
    {
      max =  *(dataset+i);
    }
    i++;
  }
  return max;
}

float StudentGrades::popStdDev(const int dataset[], const int size) {
  float avg = average(dataset, size);
  float deviation = 0;
  int i = 0;
  int n = size;
  while(i < n){
    deviation += pow((*(dataset+i)-avg),2);
    i++;
  }
  return sqrt(deviation/n);
}

float StudentGrades::smplStdDev(const int dataset[], const int size) {
  if(size <= 1){
    return +INFINITY;
  }
  float avg = average(dataset, size);
  float deviation = 0;
  int i = 0;
  int n = size;
  while(i < n){
    deviation += pow((*(dataset+i)-avg),2);
    i++;
  }
  return sqrt(deviation/(n-1));
}

// Return minimum index
int StudentGrades::minIndex(int a[], int i, int j) {
    if (i == j)
        return i;

    // Find minimum of remaining elements
    int k = minIndex(a, i + 1, j);

    // Return minimum of current and remaining.
    return (a[i] < a[k])? i : k;
}

// Recursive selection sort. n is size of a[] and index
// is index of starting element.
void StudentGrades::selection(int a[], int n, int index = 0) {
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
        copy[i] = *(dataset+i);
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
