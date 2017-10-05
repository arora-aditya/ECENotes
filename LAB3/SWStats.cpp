//
//  SWStats.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-09-27.
//
// ./SWStats <windowSize> <num1> <num2> ...

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(const int argc, const char* const argv[])
{ //Error: Unable to compute statistics over data set because ..
  if(argc < 3){
    cerr<<"Error: Unable to compute statistics over data set because of insufficient arguments; expecting atleast one number"<<endl;
    return -1;
  }

  int windowSize = atoi(argv[1]);
  int count = argc - 2;
  float values[count + windowSize - 1];
  int sizeofarray = count + windowSize - 1;
  int i = 0;

  if(windowSize <= 0){
    cerr<<"Error: Unable to compute statistics over data set because window size is insufficient"<<endl;
    return -1;
  }
  if(windowSize == 1){
    cerr<<"Warning: No compuatation occuring since window size is one"<<endl;
  }

  if(windowSize > count){
    cerr<<"Warning: Window size is bigger than number of inputted values"<<endl;
  }

  while(i < windowSize){
    values[i] = atof(argv[2]);

    i++;
  }

  while(i < sizeofarray){
    values[i] = atof(argv[i - windowSize + 3]);

    i++;
  }

  i = 0;
  // Window Size: 3
  // Sample   Value  SWMinimum SWAverage SWMaximum

  cout<<"Window Size: "<<windowSize<<endl;
  cout<<"Sample\t\tValue\t\tSWMinimum\tSWAverage\tSWMaximum\n";
  while(i < count){

    int sample = i + 1, j = i;
    float value = values[i+windowSize-1], sum = 0;
    float min = 3.402823e+38, max = -1 * 3.402823e+38;

    while(j < i + windowSize){
      if(min >  values[j])
      {
        min = values[j];
      }
      if(max <  values[j])
      {
        max = values[j];
      }
      sum +=  values[j];

      j++;

    }
    cout<<sample<<"\t\t"<<value<<"\t\t"<<min<<"\t\t"<<(sum/windowSize)<<"\t\t"<<max<<"\n";
    i++;

  }

  return 0;
}
