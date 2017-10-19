
#include <stdlib.h>
#include <limits>
#include <math.h>
#include <iostream>
using namespace std;

void formValue(float values[], float dataset[], const int size, const int currentSample, const int windowSize){
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

int main(const int argc, const char* const argv[]) {
  int size = 5;
  float dataset[] = {1, 2, 3, 4, 5};
  int windowSize = 3 ;
  int currentSample = 3;
  float min;
  float avg;
  float max;
  float smplSD;
  float median;
	float values[windowSize];
	formValue(values,dataset,size,currentSample,windowSize);
	for(int i = 0; i < windowSize; i++){
		cout<<values[i]<<" ";
	}
}
