//
//  RunningStats.cpp
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
  if(argc < 3)
  {
    cerr<<"Error: Insufficient arguments; expecting more than 1 arguments";
  }
  else{
    float min = FLT_MAX, max = -FLT_MAX, sum = 0, count = argc-1;
    cout<<"Sample\t"<<"Value\t"<<"Minimum\t"<<"Average\t"<<"Maximum\n";

    for(int i = 1; i <= count;i++)
    {
      float value = atof(argv[i]);
      if(min >  value)
      {
        min = value;
      }

      if(max <  value)
      {
        max =  value;
      }

      sum +=  value;
      cout<<i<<"\t"<<value<<"\t"<<min<<"\t"<<sum/i<<"\t"<<max<<"\n";
    }
  }
}
