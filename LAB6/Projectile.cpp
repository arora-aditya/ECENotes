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
    if(isNaN(h + v + theta + d + t + b + w)){
        return false;
    }
    float gravity = 9.80;
    float vsin = v * sin (theta * PI/180);
    float vcos = v * cos (theta * PI/180);
    float sqr = sqrt(pow(vsin, 2) - (2 * (t - h) * gravity));
    float tim = (vsin + sqr)/gravity;
    float dist = vcos * tim;
    if(dist < b + w && dist > b){
        destY = t;
        destX = dist;
        return true;
    }
    return false;
}

int main()
{   float destX = 0 , destY = 0;
    cout<<projectileDestination(std::numeric_limits<float>::quiet_NaN(), 10, 10, 45, 28, 10, 25, 5, destX, destY)<<endl;
    cout<<destX<<"\t"<<destY<<endl;
    return 0;
}
