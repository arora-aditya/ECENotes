//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <math.h>
//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

bool statistics(const float dataset[], const int size,
                float& min, float& avg, float& max,
	        float& popSD, float& smplSD, float& mdn);

float minimum(const float dataset[], const int size);
float average(const float dataset[], const int size);
float maximum(const float dataset[], const int size);
float popStdDev(const float dataset[], const int size);
float smplStdDev(const float dataset[], const int size);
float median(const float dataset[], const int size);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

bool statistics(const float dataset[], const int size, float& min, float& avg, float& max, float& popSD, float& smplSD, float& mdn) {
  if(size <= 0){
    return false;
  }
  min = minimum(dataset, size);
  max = maximum(dataset, size);
  avg = average(dataset, size);
  popSD = popStdDev(dataset, size);
  smplSD = smplStdDev(dataset, size);
  mdn = median(dataset, size);
  return true;
}

float minimum(const float dataset[], const int size) {
  float mini = 3.402823e+38;
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

float average(const float dataset[], const int size) {
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

float maximum(const float dataset[], const int size) {
  float max = -1 * 3.402823e+38;
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

float popStdDev(const float dataset[], const int size) {
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

float smplStdDev(const float dataset[], const int size) {
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

void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

float median(const float dataset[], const int size) {
  float values[size];
  for(int i = 0; i < size; i++){
    values[i] = dataset[i];
  }
  int n = size;
  int i, j;
  for (i = 0; i < n-1; i++)
    for (j = 0; j < n-i-1; j++)
      if (values[j] > values[j+1])
        swap(&values[j], &values[j+1]);
  if(size%2 == 0){
    i = size/2;
    return 0.5 * (values[i] + values[i-1]);
  }
  else{
    return values[(int)size/2];
  }
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

int main(const int argc, const char* const argv[]) {
  int size = 5;
  float dataset[] = {};
  float min;
  float avg;
  float max;
  float popStDev;
  float smplStDev;
  float median;

  if (statistics(dataset, size, min, avg, max, popStDev, smplStDev, median)) {
    cout << "Minimum: " << min << endl
	 << "Average: " << avg << endl
	 << "Median:  " << median << endl
	 << "Maximum: " << max << endl
	 << "Population Standard Deviation: " << popStDev << endl
	 << "Sample Standard Deviation:     " << smplStDev << endl;
  }
  else
    cout << "Error: unable to compute statistics" << endl;

  return 0;
}

#endif
