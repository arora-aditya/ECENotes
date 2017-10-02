//
//  NthRoot.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-09-27.
//
// Newton Rapson method
// if precision is too high for float to handle, you need an escape mechanism
// then maxIterations can be implemented
// ./NthRoot <number> <root> <precision>

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(const int argc, const char* const argv[])
{ //Error: Unable to compute Nth root because
  if(argc > 4){
    //Warning: Expecting three command-line arguments; received four; ignoring extraneous arguments.
    cerr<<"Warning: Unable to compute Nth root because expecting three command-line arguments; received "<<argc-1<<"; ignoring extraneous arguments." << endl;
  }
  else if (argc < 4){
    cerr<<"Error: Unable to compute Nth root because insufficient arguments; expecting exactly three command-line arguments." << endl;
    return -1;
  }
  float S = atof(argv[1]), precision = atof(argv[3]), xi = S/2;
  int root = atoi(argv[2]);
  if(precision < 0.00000001){
    cerr<<"Error: Unable to compute Nth root because precision is too high"<<endl;
    return -1;
  }
  else if(root == 0){
    cerr<<"Error: Unable to compute Nth root because N is zero"<<endl;
    return -1;
  }
  else if(root < 0){
    cerr<<"Error: Unable to compute Nth root because N is negative"<<endl;
    return -1;
  }
  else if(root < 2){
    cerr<<"Error: Unable to compute Nth root because N is less than 2"<<endl;
    return -1;
  }
  else if (root%2 == 0 && S < 0){
    cerr<<"Error: Unable to compute Nth root because number is negative and N is even."<<endl;
    return -1;
  }
  else if (S == 0){
    cout<<"Root("<<S<<","<<root<<") = "<<0<<endl;
    cout<<"(with precision "<<0<<")"<<endl;
    return 0;
  }

  float actual_precision = 93479823749923;
  while(actual_precision > precision){
    float xn = 1, xn_1 = 1;
    for(int i = 1; i <= root-1; i++){
       xn_1 *= xi;
    }
    xi =  ((root-1)*xi/root) + (S/(xn_1*root));
    for(int i = 1; i <= root; i++){
       xn *= xi;
    }

    actual_precision = ((S - xn)/S);
    if(actual_precision < 0){
      actual_precision *= -1;
    }

  }

  //Root(...,...) = ...
  //(with precision ...)
  cout<<"Root("<<S<<","<<root<<") = "<<xi<<endl;
  cout<<"(with precision "<<actual_precision<<")"<<endl;
  return 0;
}
