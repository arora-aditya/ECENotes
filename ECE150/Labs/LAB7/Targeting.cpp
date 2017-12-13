//
//  Targeting.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-11-08.
//
//	tolerance is 1%
// 	use bisection sort, theta = 45, v = int_max
//  think if the bunker, shoot at 90+delta

#include <iostream>
#include <stdlib.h>
#include <math.h>
#define isNaN(X) (X != X)
#define isNaN(X) (X != X) // NaN is the only float that is not equal to itself
#define PI 3.14

using namespace std;

float abc(float a, float b, float c){
    float k = pow(b,2) - 4 * a * c;
    return (-b + sqrt(k))/(2*a);
}


int projectileHelper(const float h, const float v, const float m, const float theta, const float d, const float t, const float b, const float w, int &counter){
    counter++;
	//0 found it, 1 is too large, -1 is too small, -2 is error
	float g = 9.80;
    float vsin = v * sin (theta * PI/180);
    float vcos = v * cos (theta * PI/180);
    float timt = abc(g/2, -vsin, t - h);
    float xt = vcos * timt;
    if(isNaN(h + v + theta + d + t + b + w) || h < 0 || b < 0 || v < 0 || w < 0){
        return false;
    }
    if(isNaN(xt)){
        return -1;
    }
    cout<<fabs(xt-d)<<'\t'<<theta<<'\t'<<v<<endl;
    if(xt >= b && xt <= b+w){
        if(fabs(xt - d) < 0.0001 || counter > 1000){
            return 0;
        }
        if(xt > d){
            return 1;
        }
        else{
            return -1;
        }
    }
    if(xt >= b + w){
        return 1;
    }
    if(xt <= b){
        return -1;
    }
    return 0;

}

bool hitTargetGivenVelocity(const float h, const float v, const float m,const float d,const float t, const float b, const float w, float& theta){
	if(isNaN(h + v  + d + t + b + w) || h < 0 || b < 0 || v < 0 || w < 0 || d < 0 || (theta > 90 || theta < -90)){
        return false;
    }
	// if d at theta = 45 > b + w, then no one is gonna hit it
	float thetaMax = 45;
	float thetaMin = 90;
	float thetaMid = 67.5;
    int counter = 0;
	if(projectileHelper(h, v, m, thetaMax, d, t, b, w, counter) == -1){
		return false;
	}
	int current = projectileHelper(h, v, m, thetaMid, d, t, b, w, counter);
	while(current != 0){
		if(current == 1){
			thetaMax = thetaMid;
		}
		if(current == -1){
			thetaMin = thetaMid;
		}
		thetaMid = (thetaMin + thetaMax)/2;
		current = projectileHelper(h, v, m, thetaMid, d, t, b, w, counter);
	}
	theta = thetaMid;
	return true;
}
bool hitTargetGivenAngle(const float h, const float m,const float theta, const float d,const float t, const float b, const float w, float& v){
	if(isNaN(h + v  + d + t + b + w) || h < 0 || b < 0 || v < 0 || w < 0 || d < 0 || (theta > 90 || theta < -90)){
		return false;
	}
	// if d at theta = 45 > b + w, then no one is gonna hit it
	float vMax = 2147483647;
	float vMin = 0;
	float vMid = (vMax + vMin) / 2;
    int counter = 0;
	if(projectileHelper(h, vMax, m, theta, d, t, b, w, counter) == -1){
		return false;
	}
	int current = projectileHelper(h, vMid, m, theta, d, t, b, w, counter);
	while(current != 0){
		if(current == 1){
			vMax = vMid;
		}
		if(current == -1){
			vMin = vMid;
		}
		vMid = (vMax + vMin) / 2;
		current = projectileHelper(h, vMid, m, theta, d, t, b, w, counter);
	}
	v = vMid;
	return true;
}

#ifndef MARMOSET_TESTING
int main() {

    // Some test driver code here ....

    float h = 50;
    float d = 60;
    float b = 40;
    float t = 70;
    float w = 30;
    float m = 1;

    float theta = 55.78; // Angle in degrees;
    float v = 41.8;
    //50	60	40	-30	30	1	41.8
    //50	60	40	70	30	1	73.61
    cout << "Given angle: " << theta << endl;
    cout << "Target at (" << d << "," << t << ")" << endl;
    if (hitTargetGivenAngle (h, m, theta, d, t, b, w, v)) {
      cout << "required initial velocity: " << v << endl << endl;
    }
    else {
      cout << "cannot calculate the velocity\n\n";
    }
  	v = 41.8;
    cout << "Given initial velocity: " << v << endl;
    cout << "Target at (" << d << "," << t << ")" << endl;
    if (hitTargetGivenVelocity (h, v, m, d, t, b, w, theta)) {
      cout << "required angle: " << theta << endl << endl;
    }
    else {
      cout << "cannot calculate the angle\n\n";
    }

    return 0;
}

#endif
