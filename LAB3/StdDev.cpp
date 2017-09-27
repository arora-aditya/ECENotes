//
//  StdDev.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-09-27.
//
// Newton Rapson method
// Population n
// sample deviation n-1

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main(const int argc, const char* const argv[])
{
  if (argc < 2){
    cerr<<"Error: Unable to compute statistics over data set because of insufficient arguments; expecting atleast two command-line arguments." << endl;
    return -1;
  }
  float min = 3.402823e+38, max = -1 * 3.402823e+38;
  int n = argc - 1;
  float values[n];
  int i = 0;
  float sum = 0;
  while(i < n){
    values[i] = atof(argv[i+1]);
    sum += values[i];
    if(min >  values[i])
    {
      min = values[i];
    }

    if(max <  values[i])
    {
      max =  values[i];
    }
    i++;
  }
  i = 0;
  float avg = sum/n;
  float deviation = 0;
  while(i < n){
    deviation += pow((values[i]-avg),2);
    i++;
  }
  // Number of floating-point numbers: ...
  // Minimum floating-point number: ...
  // Average floating-point number: ...
  // Maximum floating-point number: ...
  // Population standard deviation: ...
  // Sample standard deviation: ...
  if(n == 1){
    char sdev[9] = "infinity";
    cout<<"Number of floating-point numbers: "<<n<<endl;
    cout<<"Minimum floating-point number: "<<min<<endl;
    cout<<"Average floating-point number: "<<avg<<endl;
    cout<<"Maximum floating-point number: "<<max<<endl;
    cout<<"Population standard deviation: "<<sqrt(deviation/n)<<endl;
    cout<<"Sample standard deviation: "<<sdev<<endl;
  }
  else{
    float sdev = sqrt(deviation/(n-1));
    cout<<"Number of floating-point numbers: "<<n<<endl;
    cout<<"Minimum floating-point number: "<<min<<endl;
    cout<<"Average floating-point number: "<<avg<<endl;
    cout<<"Maximum floating-point number: "<<max<<endl;
    cout<<"Population standard deviation: "<<sqrt(deviation/n)<<endl;
    cout<<"Sample standard deviation: "<<sdev<<endl;
  }

}
