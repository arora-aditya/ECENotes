//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <float.h>
//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;


// Sample function for which you need to find the root

float f(const float x) {
  return 3.2*x*x*x*x - 2.1*x - 23.0;
}

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

float bisectionHelper(const float left, const float right, const float precision, const float minIntervalSize);
float bisection(const float left, const float right, const float precision, const float minIntervalSize);
#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself
//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

float bisectionHelper(const float left, const float right, const float precision, const float minIntervalSize){
    static int count = 0;
    count += 1;
    float mid = 0.5 * (left + right);
    // cout<<count<<"\t"<<left<<"\t"<<mid<<"\t"<<right<<"\n";
    float precisionActual = f(mid);
    if((fabs(precisionActual) < precision || fabs(right - left) <= minIntervalSize)?true:false){
        return 0.5 * (left + right);
    }
    else if(count > 1000?true:false){
        return std::numeric_limits<float>::quiet_NaN();
    }
    else if(f(mid) > 0){
        return bisectionHelper(left,mid,precision,minIntervalSize);
    }
    else{
        return bisectionHelper(mid,right,precision,minIntervalSize);
    }
}

float bisection(const float left, const float right, const float precision, const float minIntervalSize) {
    if(left > right || precision < 0 || precision > 1 || minIntervalSize < 0 || f(left) * f(right) > 0 || isNaN(f(left)) || isNaN(f(right))){
        return std::numeric_limits<float>::quiet_NaN();
    }
    if(left == right && f(left) != 0){
        return std::numeric_limits<float>::quiet_NaN();
    }
    if(f(left) < f(right)){
        return bisectionHelper(left, right, precision, minIntervalSize);
    }
    else{
        return bisectionHelper(right, left, precision, minIntervalSize);
    }
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING



int main(const int argc, const char* const argv[]) {
    // cout<<bisection(0,2.04,0.0000001,0.00000002)<<endl;
    cout<<f(bisection(-5,0,0.0000001,0.00000002))<<endl;
    // cout<<bisection(10,0,0.0001,std::numeric_limits<float>::quiet_NaN())<<endl;
    // cout<<f(bisection(10,0,0.0001,std::numeric_limits<float>::quiet_NaN()))<<endl;
    // cout<<bisection(-5,0,0.000000001,0.000000002)<<endl;
    // cout<<f(bisection(0,10,0.0001,-0.0002))<<endl;
    // cout<<bisection(0,10,-0.0001,0.0002)<<endl;
    // cout<<f(bisection(0,10,-0.0001,0.0002))<<endl;
    return 0;
}

#endif
