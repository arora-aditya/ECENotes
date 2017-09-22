//
//  Braking.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-09-13.
//
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>


using namespace std;

int main( const int argc, const char* const argv[])
{   float v = atof(argv[1]), d = atof(argv[2]);
    
    float acc = v*v/(2*d);
    
    cout<<"Initial car velocity: "<<v<<" m/s"<<endl;
    cout<<"Distance to obstacle: "<<d<<" m"<<endl;
    cout<<"Minimum deceleration: "<<acc<<" m/s/s"<<endl;
    cout<<"Maximum stopping time: "<<v/acc<<" s"<<endl;
    
    return 0;
}
