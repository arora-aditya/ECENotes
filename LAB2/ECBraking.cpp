//
//  ECBraking.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-09-20.
//
// ./ECBraking <velocity> <distance> <maximum acceptable deceleration>

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(const int argc, const char* const argv[])
{
  float v = atof(argv[1]), d = atof(argv[2]), max_acc = atof(argv[3]);
  float acc = fabs(v*v/(2*d));

  if(argc > 4){
    //     Warning: Expecting three command-line arguments; received ...; ignoring extraneous arguments
    cerr<<"Warning: Expecting three command-line arguments; received "<<argc-1<<"; ignoring extraneous arguments" << endl;
  }
  else if (argc < 4){
    cerr<<"Error: Expecting exactly three command-line arguments;" << endl;
    return -1;
  }
  else if (max_acc < 0){
    cerr<<"Error: Only positive accelaration allowed;\n";
    return -1;
  }
  if((v > 0 && d < 0) || (v < 0 && d > 0)){
    cout<<"There is no possibility of collision because the velocity is in the opposite direction of distance\n";
  }
  else if(v == 0){
    cout<<"There is no possibility of collision because the velocity is zero\n";
  }
  else if(acc <= max_acc){
    cout<<"Initial car velocity: "<<v<<" m/s"<<endl;
    cout<<"Distance to obstacle: "<<d<<" m"<<endl;
    cout<<"Minimum deceleration: "<<fabs(acc)<<" m/s/s"<<endl;
    cout<<"Maximum stopping time: "<<fabs(v/acc)<<" s"<<endl;
  }
  else if(max_acc == 0){
    cout<<"Crash will occur in "<<fabs(d/v)<<" seconds at velocity "<<v<<"m/s; deploying airbags.\n";
  }
  else if(acc > max_acc){
    if(d > 0){
      acc = max_acc;
      float u = pow(fabs(pow(v,2)-(2*acc*d)), 0.5)*(v/fabs(v));
      //    'Crash will occur in ... seconds at velocity ...m/s; deploying airbags.'
      cout<<"Crash will occur in "<<fabs((v-u)/acc)<<" seconds at velocity "<<u<<"m/s; deploying airbags.\n";
    }
    else{
      acc = max_acc;
      float u = pow(fabs(pow(v,2)+(2*acc*d)), 0.5)*(v/fabs(v));
      //    'Crash will occur in ... seconds at velocity ...m/s; deploying airbags.'
      cout<<"Crash will occur in "<<fabs((v-u)/acc)<<" seconds at velocity "<<u<<"m/s; deploying airbags.\n";
    }

  }

  return 0;
}
