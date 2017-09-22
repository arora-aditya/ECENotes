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
  float acc = v*v/(2*d);

  if(argc > 4){
    cerr << "Warning: Expecting three command-line arguments; received greater than three; ignoring extraneous arguments." << endl;
    return -1;
  }
  else if (argc < 4){
    cerr << "Warning: Expecting exactly three command-line arguments;" << endl;
  }
  else if((v > 0 && d < 0) || (v < 0 && d > 0)){
    cout<< "There is no possibility of collision because the velocity is in the opposite direction of distance\n";
  }
  else if(v == 0){
    cout<<"There is no possibility of collision because "<<"the velocity is zero\n";
  }
  else if(acc <= max_acc){
    cout<<"Initial car velocity: "<<v<<" m/s"<<endl;
    cout<<"Distance to obstacle: "<<d<<" m"<<endl;
    cout<<"Minimum deceleration: "<<acc<<" m/s/s"<<endl;
    cout<<"Maximum stopping time: "<<v/acc<<" s"<<endl;
  }
  else if(max_acc == 0){
    cout<<"Crash will occur in "<<d/v<<" seconds at velocity "<<v<<" m/s; deploying airbags.\n";
  }
  else{
    acc = max_acc;
    float u = pow(abs(pow(v,2)-(2*acc*d)), 0.5);
    //     Crash will occur in      ...        seconds at velocity   ...  m/s; deploying airbags.
    //Crash will occur in ... seconds at velocity ...m/s; deploying airbags.
    cout<<"Crash will occur in "<<(v-u)/acc<<" seconds at velocity "<<u<<" m/s; deploying airbags.\n";
  }

  return 0;
}
