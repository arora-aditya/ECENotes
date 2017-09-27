//
//  GcdLcm.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-09-27.

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(const int argc, const char* const argv[])
{
  if(argc > 3){
    //Warning: Expecting three command-line arguments; received four; ignoring extraneous arguments.
    cerr<<"Warning: Expecting two command-line arguments; received "<<argc-1<<"; ignoring extraneous arguments." << endl;
  }
  else if (argc < 3){
    cerr<<"Error: Unable to compute GCD and/or LCM because of insufficient arguments; expecting exactly two command-line arguments." << endl;
    return -1;
  }
  int x = atoi(argv[1]), y = atoi(argv[2]), gcd = -1;
  int w = atoi(argv[1]), z = atoi(argv[2]);
  if (!(x && y)){
    cerr<<"Error: Unable to compute GCD and/or LCM because one of the numbers is zero"<<endl;
    return -1;
  }
  if (x < 0 || y < 0){
    cerr<<"Error: Unable to compute GCD and/or LCM because one or both of the numbers is less than zero"<<endl;
    return -1;
  }
  while(x !=  y){
    if ( x < y ){
      int t = x;
      x = y;
      y = t;
    }
    x -= y;
  }

  // Euclid's algorithm
  // GCD(342,198) = 18
  // LCM(342,198) = 3762

  gcd = x;

  cout<<"GCD("<<w<<", "<<z<<") = "<<gcd<<endl;
  cout<<"LCM("<<w<<", "<<z<<") = "<<(int) (w/gcd)*z<<endl;

  return 0;
}
