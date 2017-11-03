//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <math.h>
#include <limits>
#define PI 3.14159265
#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself
//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY);

float abc(float a, float b, float c){
    float k = pow(b,2) - 4 * a * c;
    return (-b + sqrt(k))/(2*a);
}

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

bool projectileDestination(const float h, const float v, const float m, const float theta, const float d, const float t, const float b, const float w, float& destX, float& destY) {
    float g = 9.80;
    float vsin = v * sin (theta * PI/180);
    float vcos = v * cos (theta * PI/180);
    float timt = abc(g/2, -vsin, t - h);
    float tim0 = abc(g/2, -vsin, -h);
    float timHb = b/vcos;
    float xt = vcos * timt;
    float x0 = vcos * tim0;
    float yb = h + (vsin * timHb) - (g/2 * timHb * timHb);
    // cout<<tim<<'\t'<<vsin<<'\t'<<vcos<<'\t'<<g<<'\n';
    if(isNaN(h + v + theta + d + t + b + w) || h < 0 || t < 0 || b < 0 || v < 0 || w < 0){
        return false;
    }
    if(vcos < 0){
        destX = vcos * tim0;
        destY = 0;
        return true;
    }
    else if((v == 0 || theta == 90) && b != 0){
        destX = 0;
        destY = h;
        return true;
    }
    if(xt >= b && xt <= b+w){
        destX = xt;
        destY = t;
        return true;
    }
    if(xt >= b + w){
        destX = x0;
        destY = 0;
        return true;
    }
    if(x0 <= b){
        destX = x0;
        destY = 0;
        return true;
    }
    if(yb <= t && yb >= 0){
        destX = b;
        destY = yb;
        return true;
    }
    return false;

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

  // Some test driver code here ....
//   h, b, t, w, m, v, theta
// 50, 30, 60, 20, 1, 18.4, 17.89
  float h = 50;
  float v = 18.4;
  float m = 1;
  float theta = 17.89;        // Angle in degrees; will need to be converted by function
  float d = 100;
  float t = 60;
  float b = 30;
  float w = 20;

  float hitsAtX;
  float hitsAtY;

  if (projectileDestination(h,v,m,theta,d,t,b,w,hitsAtX,hitsAtY))
    cout << "Projectile hit at (" << hitsAtX << ", " << hitsAtY << ")" <<endl;
  else
    cout << "Unable to calculate where projectile hits." << endl;
  return 0;
}

#endif

//14, 4.36481
