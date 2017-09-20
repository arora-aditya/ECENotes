//
//  DataTypes.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-09-13.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <float.h>
using namespace std;

int main( const int argc, const char*const argv[]) {
    int x;
    unsigned int y;// Need #include <stdlib.h> for atoi
    x = atoi(argv[1]);   // Convert argument 1 to int
    y = x;
    // Output the values of x and y to cout...
    cout<<"The value of x is "<<x<<endl;
    cout<<"The value of y is "<<y<<endl;
    // Output the most significant bit of x to cout...
    cout<<"The most significant bit of x is "<< ((unsigned)x >> (sizeof(x)*CHAR_BIT-1))<<endl;
    // Output the most significant bit of y to cout
    cout<<"The most significant bit of y is "<< ((unsigned)y >> (sizeof(x)*CHAR_BIT-1))<<endl;
    
    cout<<"Type: \"signed char\"; Size: "<<sizeof(signed char)<<" bytes; Minimum value: "<<SCHAR_MIN<<" ; Maximum value: "<<SCHAR_MAX<<endl;
    cout<<"Type: \"short int\"; Size: "<<sizeof(short int)<<" bytes; Minimum value: "<<SHRT_MIN<<" ; Maximum value: "<<SHRT_MAX<<endl;
    cout<<"Type: \"int\"; Size: "<<sizeof(int)<<" bytes; Minimum value: "<<INT_MIN<<" ; Maximum value: "<<INT_MAX<<endl;
    cout<<"Type: \"long int\"; Size: "<<sizeof(long int)<<" bytes; Minimum value: "<<LONG_MIN<<" ; Maximum value: "<<LONG_MAX<<endl;
    cout<<"Type: \"long long int\"; Size: "<<sizeof(long long int)<<" bytes; Minimum value: "<<LLONG_MIN<<" ; Maximum value: "<<LLONG_MAX<<endl;
    cout<<"Type: \"unsigned char\"; Size: "<<sizeof(unsigned char)<<" bytes; Minimum value: "<<"0"<<" ; Maximum value: "<<UCHAR_MAX<<endl;
    cout<<"Type: \"unsigned short int\"; Size: "<<sizeof(unsigned short int)<<" bytes; Minimum value: "<<"0"<<" ; Maximum value: "<<USHRT_MAX<<endl;
    cout<<"Type: \"unsigned int\"; Size: "<<sizeof(unsigned int)<<" bytes; Minimum value: "<<"0"<<" ; Maximum value: "<<UINT_MAX<<endl;
    cout<<"Type: \"unsigned long int\"; Size: "<<sizeof(unsigned long int)<<" bytes; Minimum value: "<<"0"<<" ; Maximum value: "<<ULONG_MAX<<endl;
    cout<<"Type: \"unsigned long long int\"; Size: "<<sizeof(unsigned long long int)<<" bytes; Minimum value: "<<"0"<<" ; Maximum value: "<<ULLONG_MAX<<endl;
    cout<<"Type: \"float\"; Size: "<<sizeof(float)<<" bytes; Minimum value: "<<FLT_MIN<<" ; Maximum value: "<<FLT_MAX<<endl;
    cout<<"Type: \"double\"; Size: "<<sizeof(double)<<" bytes; Minimum value: "<<DBL_MIN<<" ; Maximum value: "<<DBL_MAX<<endl;
    cout<<"Type: \"long double\"; Size: "<<sizeof(long double)<<" bytes; Minimum value: "<<LDBL_MIN<<" ; Maximum value: "<<LDBL_MAX<<endl;

    return 0;
}
