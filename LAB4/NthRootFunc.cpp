//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <limits>
#include <stdlib.h>
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

float NthRoot(const float S, const int N, const float precision);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the Nth root of S with
// precision.
//

float NthRoot(const float S, const int N, const float precision) {
  if((precision < 0.00000001) || (N%2 == 0 && S < 0) || (N<2)){
    return std::numeric_limits<float>::quiet_NaN();
  }
  else if (S == 0){
    return 0;
  }

  float actual_precision = 93479823749923, xi = S/2;;
  while(actual_precision > precision){
    float xn = 1, xn_1 = 1;
    for(int i = 1; i <= N-1; i++){
       xn_1 *= xi;
    }
    xi =  ((N-1)*xi/N) + (S/(xn_1*N));
    for(int i = 1; i <= N; i++){
       xn *= xi;
    }

    actual_precision = ((S - xn)/S);
    if(actual_precision < 0){
      actual_precision *= -1;
    }
  }
  return xi;
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

  if (argc < 4) {
    cerr << "Error: Usage: " << argv[0] << " <number> <root> <precision>; exiting" << endl;
    return -1;
  }

  float root = NthRoot(atof(argv[1]),atoi(argv[2]),atof(argv[3]));
  if (isNaN(root))
    cerr << "Unable to compute " << argv[2] << "th root of " << argv[1] << " with precision " << argv[3] << endl;
  else
    cout << "Root(" << argv[1] << "," << argv[2] << ") = " << root << endl
	 << "(with precision " << argv[3] << ")" << endl;

  return 0;
}

#endif
