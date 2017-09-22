//
//  Statistics.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-09-20.
//
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

using namespace std;

int main( const int argc, const char* const argv[])
{
  if(argc <= 1){
    cerr<<"Error: Unable to compute statistics over data set because need atleast one argument to compute on\n";
    return -1;
  }
  else
  {
    float min = FLT_MAX, max = -FLT_MAX, sum = 0, count = argc-1;

    int i = 1;
    while(i <= count)
    {

      if(min >  atof(argv[i]))
      {
        min = atof(argv[i]);
      }

      if(max <  atof(argv[i]))
      {
        max =  atof(argv[i]);
      }

      sum +=  atof(argv[i]);

      i+=1;
    }
    // Number of floating-point numbers: ...
    // Minimum floating-point number: ...
    // Average floating-point number: ...
    // Maximum floating-point number: ...
    cout<<"Number of floating-point numbers: "<<count<<endl;
    cout<<"Minimum floating-point number: "<<min<<endl;
    cout<<"Average floating-point number: "<<sum/count<<endl;
    cout<<"Maximum floating-point number: "<<max<<endl;


    }
  return 0;
}
