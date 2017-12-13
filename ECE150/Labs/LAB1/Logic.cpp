//
//  Logic.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-09-13.
//
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

int main( const int argc, const char*const argv[]) {
    int P;
    int Q;
    
    P = atoi(argv[1]);     // Convert argument 1 to int
    Q = atoi(argv[2]);     // Convert argument 2 to int
    
    cout<<"P: "<<P<<endl;
    cout<<"Q: "<<Q<<endl;
    cout<<"P AND Q: "<<(P && Q)<<endl;
    cout<<"P OR Q: "<<(P || Q)<<endl;
    cout<<"NOT P: "<<(!P)<<endl;
    cout<<"NOT Q: "<<(!Q)<<endl;
    
    return 0;
}
