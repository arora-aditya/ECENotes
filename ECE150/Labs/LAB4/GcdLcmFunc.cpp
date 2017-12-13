//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <limits.h>
//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

int greatestCommonDenominator(const int, const int);
int leastCommonMultiple(const int, const int);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

int greatestCommonDenominator(const int a, const int b) {
  int x = a, y = b;
  if ((!(x && y)) || (x < 0 || y < 0)){
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

  return x;
}

int leastCommonMultiple (const int a, const int b) {

  int gcd = greatestCommonDenominator(a,b);

  if((int) ((a/gcd) * b) > INT_MAX){
    return -2;
  }

  if (gcd == -1){
    return -1;
  }
  return (int) ((a/gcd) * b);
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

  if (argc < 3) {
    cerr << "Error: Usage: " << argv[0] << "<num1> <num2>; eaiting" << endl;
    return -1;
  }

  int gcd = greatestCommonDenominator(atoi(argv[1]),atoi(argv[2]));
  if (gcd < 0)
    cerr << "Unable to compute GCD(" << argv[1] << "," << argv[2] << ")" << endl;
  else
    cout << "GCD(" << argv[1] << "," << argv[2] << ") = " << gcd << endl;

  int lcm = leastCommonMultiple(atoi(argv[1]),atoi(argv[2]));
  if (lcm < 0)
    cerr << "Unable to compute LCM(" << argv[1] << "," << argv[2] << ")" << endl;
  else
    cout << "LCM(" << argv[1] << "," << argv[2] << ") = " << lcm << endl;


  return 0;
}

#endif
