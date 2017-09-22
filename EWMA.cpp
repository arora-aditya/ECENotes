//
//  EWMA.cpp
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

int main( const int argc, const char* const argv[]){
    if(argc < 4){
        cerr<<"Error: Insufficient arguments; expecting more than 4 arguments\n";
        return -1;
    }
    else if(atof(argv[2]) <= 0){
        cerr<<"Error: Invalid age; expeceted value to be greater than zero\n";
        return -1;
    }
    else if(atof(argv[3]) <= 1 &&  atof(argv[3]) >= 0){
        cerr<<"Error: Invalid weightage; expected value between 0 and 1\n";
        return -1;
    }
    else{
        float alpha = atof(argv[1]);
        float age = atof(argv[2]);
        float min = FLT_MAX, min_age = 0;
        float max = -FLT_MAX, max_age = 0;
        float sum = 0, count = argc - 2;
        float avg = atof(argv[3]);

        cout<<"Sample\t"<<"Value\t"<<"Minimum\t"<<"EWMA\t"<<"Maximum\n";

        for(int i = 1; i < count; i++){
            float value = atof(argv[i+2]);

            if(min > value || min_age >= age){
                min = value;
                min_age = 0;
            }

            if(max < value || max_age >= age){
                max =  value;
                max_age = 0;
            }

            min_age += 1;
            max_age += 1;

            avg = ((alpha)*value) + ((1-alpha)*avg);

            cout<<i<<"\t"<<value<<"\t"<<min<<"\t"<<avg<<"\t"<<max<<"\n";
        }
        return 0;
    }
}
