//
//  Drag.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-11-21.
//
//

#include <iostream>
#include <math.h>
#define isNaN(X) (X != X) // NaN is the only float that is not equal to itself
#define PI 3.14
using namespace std;

struct ball{
	float x;
	float y;
	float vX;
	float vY;
	float launchAngle;
	float aX;
	float aY;
	float m;
	float b;
	float airResistCoefficient;
	float deltaTime;
	float storedH;

	ball(float v, float theta, float h, float k, float mass, float step){
		launchAngle = theta;
		x = 0;
		y = h;
		aY = -9.80;
		aX = 0;
		vX = v * cos (theta * PI/180);
		vY = v * sin (theta * PI/180);
		b = k;
		m = mass;
		airResistCoefficient = b/m;
		deltaTime = step;
		storedH = h;
	}

	void Move(){
		float vSq = (vX * vX + vY * vY);
		float v = sqrt(vSq);
		x += vX * deltaTime;
		y += vY * deltaTime;
		float resist = vSq * airResistCoefficient;
		vX += (aX - (vX * resist/v)) * deltaTime;
		if(vX < 0){
			vX = 0;
		}
		vY += (aY - (vY * resist/v)) * deltaTime;

	}

	void updateV(float v){
		vX = v * cos (launchAngle * PI/180);
		vY = v * sin (launchAngle * PI/180);
		x = 0;
		y = storedH;
	}
};

int areWeThereYet(ball ba, float t, float d, float w,float b,float precision = 0.001){
	if(ba.storedH > t){
		if(fabs(ba.x - d) < precision && fabs(ba.y - t) < precision){
			return 0;
		}
		else if(fabs(ba.x - d) < 0.1 && ba.y - t < 0){
			return +2;
		}
		else if(fabs(ba.x - d) < 0.1 && ba.y - t > 0){
			return -2;
		}
		else if(ba.x - d < 0 && ba.vY + ba.vX != 0){
			return +2;
		}
		else if(ba.x - d > 0 || ba.vY + ba.vX == 0){
			return -2;
		}
	}
	else if(t > 0){
		if(fabs(ba.x - d) < precision && fabs(ba.y - t) < precision){
			return 0;
		}
		else if(fabs(ba.x - d) < 0.1 && ba.y - t < 0){
			return +2;
		}
		else if(fabs(ba.x - d) < 0.1 && ba.y - t > 0){
			return -2;
		}
		else if(ba.x - d < 0 && ba.vY + ba.vX != 0){
			return +2;
		}
		else if(ba.x - d > 0 || ba.vY + ba.vX == 0){
			return -2;
		}
	}
	else if(t < 0){
		if(ba.y < t && ba.x < b){
			return 2;
		}
		if(fabs(ba.x - d) < precision && fabs(ba.y - t) < precision){
			return 0;
		}
		else if(fabs(ba.x - d) < 1 && ba.y > 1.1 * t){
			return -2;
		}
		else if(fabs(ba.x - d) < 1 && ba.y < 1.1 * t){
			return +2;
		}
		else if(ba.x - d < 0 && ba.vY + ba.vX != 0){
			return +2;
		}
		else if(ba.x - d > 0 || ba.vY + ba.vX == 0){
			return -2;
		}
	}

}

int simulate(ball& ba, float t, float d, float b){
	float counter = 0;
	if(t < ba.storedH && t > 0){
		float counter = 0;
		while(ba.y >= t && counter < 10000 && ba.x <= d && ba.vY + ba.vX != 0){
			ba.Move();
			counter++;
		}
	}
	else{
		if(t > 0){
			float counter = 0;
			while(ba.y <= t && counter < 10000 && ba.x <= d && ba.vY + ba.vX != 0){
				ba.Move();
				counter++;
			}
			if(ba.x <= d){
				counter = 0;
				ba.Move();
				ba.Move();
				while(ba.y >= t && counter < 10000 && ba.x <= d && ba.vY + ba.vX != 0){
					ba.Move();
					counter++;
				}
			}
		}
		else{
			counter = 0;
			// cout<<counter;
			while(ba.y >= t && counter < 1000000){
				ba.Move();
				if(ba.y < 0 && ba.x < b){
					return -1;
				}
				counter++;
			}

		}

	}
	return 0;
}
// float signum(float x){
// 	return x/fabs(x);
// }

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
    // cout<<fabs(xt-d)<<'\t'<<theta<<'\t'<<v<<endl;
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

bool hitTargetGivenAngle2(const float h, const float m,const float theta, const float d,const float t, const float b, const float w, float& v){
	if(isNaN(h + d + t + b + w + theta) || h < 0 || b < 0 || v < 0 || w < 0 || d < 0 || (theta > 90 || theta < -90) ){
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

bool hitTargetGivenAngle(const float h, const float m,const float theta, const float d,const float step, const float k,const float t, const float b, const float w, float& v){
	if(isNaN(h + d + t + b + w + k) || k < 0 || h < 0 || b < 0 || w < 0 || d < 0 || (theta > 90 || theta < -90) || m < 0){
		return false;
	}
	if(k == 0){
		return hitTargetGivenAngle2(h, m, theta, d, t, b, w, v);
	}
	float vMin = 0;
	float vMax = 1000;
	float vMid = 0.5 * (vMax + vMin);
	ball bMax(vMax, theta, h, k, m, step);
	ball bMid(vMid, theta, h, k, m, step);
	simulate(bMax, t, d,b);
	if(areWeThereYet(bMax, t, d, w,b) == 2){
		return false;
	}
	else{
		simulate(bMid,t,d,b);
		int areWeThere = areWeThereYet(bMid, t, d, w,b), counter = 0;
		while(areWeThere != 0 && counter < 100){
			simulate(bMid,t,d,b);
			areWeThere = areWeThereYet(bMid, t, d, w,b);
			cout<<vMin<<'\t'<<vMid<<'\t'<<vMax<<'\t'<<'('<<bMid.x<<','<<bMid.y<<')'<<'\t'<<areWeThere<<'\t'<<simulate(bMid, t, d, b)<<endl;
			if(areWeThere == 2){
				vMin = vMid;
			}
			if(areWeThere == -2){
				vMax = vMid;
			}
			vMid = 0.5 * (vMax + vMin);
			bMid.updateV(vMid);
			counter++;
		}
	}
	v = vMid;
	bMid.updateV(vMid);
	simulate(bMid,t,d,b);
	if(areWeThereYet(bMid, t, d, w,b, 10) != 0){
		return false;
	}
	v = vMid;
	bMid.updateV(vMid);
	return true;

}
#ifndef MARMOSET_TESTING
int main()
{	float h = 100, m = 10, theta = 45, v = 10000, d = 132, b = 120, w = 30, k = 0.0820, step = 0.001, t = 20.1;
	// h50,d60,b40,t30,w30,m10,theta45,step0.00001,k0.5
	h = 50, d = 50, b = 40, t = -60, w = 5, m = 30, k = 0.0030, theta=26;
	if(hitTargetGivenAngle(h, m, theta, d, step, k, t, b, w, v)){
		cout<<endl<<v<<endl;;
	}
	else{
		cout<<-1;
	}

	return 0;
}
#endif
