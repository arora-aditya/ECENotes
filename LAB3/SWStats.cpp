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
{
  if(argc < 3){
    cerr<<"Error: Unable to compute statistics over data set because of insufficient arguements; expecting atleast one"<<endl;
    return -1;
  }
  int windowSize = atoi(argv[1]);
  if(windowSize <= 0){
    cerr<<"Error: Unable to compute statistics over data set because window size is insufficient"<<endl;
    return -1;
  }
  if(windowSize == 1){
    cerr<<"Warning: No compuatation occuring since window size is one"<<endl;
  }

  int count = argc - 2;
  float values[count+ windowSize - 1];
  int sizeofarray = sizeof(values)/sizeof(float);
  int i = 0;

  if(windowSize < sizeofarray){
    cerr<<"Warning: Window size is bigger than number of inputted values"<<endl;
  }

  while(i < windowSize){
    values[i] = atof(argv[2]);
    i++;
  }

  while(i < sizeofarray){
    values[i] = atof(argv[i]);
    i++;
  }

  i = 0;
  // Window Size: 3
  // Sample   Value  SWMinimum SWAverage SWMaximum

  cout<<"Window Size: "<<windowSize<<endl;
  cout<<"Sample\t"<<"Value\t"<<"SWMinimum\t"<<"SWAverage\t"<<"SWMaximum\n";
  while(i < sizeofarray - windowSize + 1){

    int sample = i + 1, j = i;
    float value = values[i+2], sum = 0;
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
    cout<<sample<<"\t"<<value<<"\t"<<min<<"\t        "<<(float)(sum/windowSize)<<"\t        "<<max<<"\n";
    i++;

  }

  return 0;
}
