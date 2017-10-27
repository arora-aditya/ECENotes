//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allefted them ...
//

#include <stdlib.h>
#include <limits>
//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;


// Sample function for which you need to find the root

float f(const float x) {
  return 3.2*x*x*x - 2.1*x - 23.0;
}

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

float bisectionHelper(const float left, const float right,
		      const float precision, const float minIntervalSize
		      ... );
float bisection(const float left, const float right,
		const float precision, const float minIntervalSize);


//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

float bisectionHelper(const float left, const float right, const float precision, const float minIntervalSize, float count){
    return count += 1;
}

float bisection(const float left, const float right, const float precision, const float minIntervalSize) {
    float low = left;
    float high = right;
    if(low >= high){
        return  std::numeric_limits<float>::quiet_NaN();
    }
    float count = 0;
    float mid = 0.5 * (low + high);
    float precisionActual = f(mid);
    while((precisionActual > precision || high - low > minIntervalSize) && count < 10000){
        if(f(mid) > 0){
            bisection(left,mid,precision,minIntervalSize);
        }
        else{
            bisection(mid,right,precision,minIntervalSize);
        }
        mid = 0.5 * (low + high);
        precisionActual = f(mid);
        count = bisectionHelper(low, high, precision, minIntervalSize, count);
    }
    return mid;
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

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
    cout<<bisection(0,10,0.0001,0.0002)<<endl;
    cout<<f(bisection(0,10,0.0001,0.0002));
    return 0;
}

#endif
