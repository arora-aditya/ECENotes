//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <limits>
#include <math.h>
//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

int SWStats(const float dataset[], const int size, const int currentSample, const int windowSize, float& min,  float& avg, float& max, float& smplSD, float& mdn);
int SWMinimum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& minimum);
int SWAverage(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& average);
int SWMaximum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& maximum);
int SWSmplStdDev(const float dataset[], const int size,
		 const int currentSample, const int windowSize,
		 float& smplStdDev);
int SWMedian(const float dataset[], const int size,
	     const int currentSample, const int windowSize,
	     float& median);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

int SWStats(const float dataset[], const int size, const int currentSample, const int windowSize, float& min, float& avg, float& max, float& smplSD, float& mdn){
	if(windowSize <= 0){
		return -1;
	}
	if(windowSize == 1){
    return 1;
  }
	if(windowSize > size){
    return 2;
  }
	SWMinimum(dataset, size, currentSample, windowSize, min);
	SWAverage(dataset, size, currentSample, windowSize, avg);
	SWMaximum(dataset, size, currentSample, windowSize, max);
	SWMedian(dataset, size, currentSample, windowSize, mdn);
	SWSmplStdDev(dataset, size, currentSample, windowSize, smplSD);

	return 0;
}

void formValue(float values[],const float dataset[], const int size, const int currentSample, const int windowSize){
	for(int i = 0; i < windowSize; i++){
		values[i] = dataset[(currentSample-windowSize+1>=0)?currentSample-windowSize+1:0];
	}
	int currentPos = currentSample;
	int i = windowSize-1;
	while(i >= 0 && currentPos>=0){
		values[i] = dataset[currentPos];
		i--;
		currentPos--;
	}
}

int SWMinimum(const float dataset[], const int size, const int currentSample, const int windowSize, float& minimum) {
	float values[windowSize];
	float min = 3.402823e+38;
	formValue(values,dataset,size,currentSample,windowSize);
	for(int i = 0; i < windowSize; i++){
		if(min >  values[i])
		{
			min = values[i];
		}
	}
	minimum = min;
	return 0;
}

int SWAverage(const float dataset[], const int size, const int currentSample, const int windowSize,
	      float& average) {
	float values[windowSize];
	float sum = 0;
	formValue(values,dataset,size,currentSample,windowSize);
	for(int i = 0; i < windowSize; i++){
		sum += values[i];
	}
	average = sum/windowSize;
	return 0;
}

int SWMaximum(const float dataset[], const int size, const int currentSample, const int windowSize, float& maximum) {
	float values[windowSize];
	float max = -3.402823e+38;
	formValue(values,dataset,size,currentSample,windowSize);
	for(int i = 0; i < windowSize; i++){
		if(max < values[i])
		{
			max = values[i];
		}
	}
	maximum = max;
	return 0;
}

float average(float dataset[],int size) {
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

int SWSmplStdDev(const float dataset[], const int size, const int currentSample, const int windowSize, float& smplStdDev) {
	if(windowSize == 1){
		smplStdDev = std::numeric_limits<float>::infinity();
	}
	int n = windowSize;
	float values[windowSize];
	formValue(values,dataset,size,currentSample,windowSize);
	float avg = average(values, windowSize);
  float deviation = 0;
  int i = 0;
  while(i < windowSize){
    deviation += pow((values[i]-avg),2);
    i++;
  }
  smplStdDev = sqrt(deviation/(n-1));
	return 0;
}

void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int SWMedian(const float dataset[], const int size, const int currentSample, const int windowSize, float& median) {
	float values[windowSize];
	formValue(values,dataset,size,currentSample,windowSize);
	int n = windowSize;
  int i, j;
  for (i = 0; i < n-1; i++)
    for (j = 0; j < n-i-1; j++)
      if (values[j] > values[j+1])
        swap(&values[j], &values[j+1]);
  if(windowSize%2 == 0){
    i = windowSize/2;
    median =  0.5 * (values[i] + values[i-1]);
  }
  else{
    median =  values[(int)windowSize/2];
  }
	return 0;
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
  int size = 16;
  float dataset[] = {1, 2, 3,6,6,3,2,1,4,5,4,3,2,3, 4, 5};
  int windowSize = 3 ;
  int currentSample = 0;
  float min;
  float avg;
  float max;
  float smplSD;
  float median;

  cout << "Sample \t Minimum \t Average \t Median \t Maximum \t Sample Standard Deviation" << endl;

  while (currentSample < size) {
    int retCode = SWStats(dataset, size, currentSample, windowSize, min, avg, max, smplSD, median);
    if (retCode >= 0) {
      cout << currentSample << "\t " << min << "\t " << avg << "\t " << max << "\t " << median << "\t " << smplSD << endl;
      if (retCode > 0)
	cerr << "Warning: something weird happened, but we computed stats anyway ... YMMV" << endl;
    }
    else {
      cerr << "Error: unable to compute sliding-window statistics; exiting" << endl;
      return(-1);
    }
    ++currentSample;
  }
  return 0;
}

#endif
