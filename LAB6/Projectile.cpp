//
//  Projectile.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-10-31.
//
// https://i.imgur.com/i2Zb9tl.jpg

#include <iostream>
#include <math.h>

#define PI 3.14159265
#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself
using namespace std;

bool projectileDestination(const float h, const float v, const float m, const float theta, const float d, const float t, const float b, const float w, float& destX, float& destY){
    if(isNaN(h + v + theta + d + t + b + w) || v * cos (theta * PI/180) < 0 || h < 0 || t < 0){
        return false;
    }
    if(v == 0 && b !=0){
        return false;
    }
    float gravity = 9.80;
    float vsin = v * sin (theta * PI/180);
    float vcos = v * cos (theta * PI/180);
    float sqr = sqrt(pow(vsin, 2) - (2 * (t - h) * gravity));
    float tim = (vsin + sqr)/gravity;
    float dist = vcos * tim;
    if(dist <= b + w && dist >= b){
        destY = t;
        destX = dist;
        return true;
    }
    else{
        sqr = sqrt(pow(vsin, 2) + (2 * (h) * gravity));
        tim = (vsin + sqr)/gravity;
        dist = vcos * tim;
        if(dist > b + w || dist < b){
            destY = t;
            destX = dist;
            return true;
        }
        else{
            tim = b/vcos;
            destY = (vsin * tim) - (0.5 * gravity * tim * tim);
            destX = b;
            return true;
        }
    }
    return false;
}

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {

  // Some test driver code here ....

  float h = 10;
  float v = 10;
  float m = 10;
  float theta = 45;        // Angle in degrees; will need to be converted by function
  float d = 100;
  float t = 5;
  float b = 97;
  float w = 5;

  float hitsAtX;
  float hitsAtY;

  if (projectileDestination(50, 100, 30, 20, 20, 1, 9.2, 67.89, hitsAtX, hitsAtY))
    cout << "Projectile hit at (" << hitsAtX << ", " << hitsAtY << ")" <<endl;
  else
    cout << "Unable to calculate where projectile hits." << endl;
  return 0;
}

#endif
