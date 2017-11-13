//  StringToFloat.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-11-08.
//
//	tolerance is 1%
//  readeable state machine to be submitted to learn

#include <iostream>
#include <math.h>
#define isNaN(X) (X != X)

using namespace std;

bool stringToFloat(const char input[], float& value) {
    float result = 0;
    int sign = 1;
    int i = 0;
    if(input[0] == '\0') {
        return false;
    }
    if(input[i] == '-' || input[i] == '+') sign = (input[i++] == '-')? -1 : 1;
    while('0' <= input[i] && input[i] <= '9') {
        result = result*10 + (input[i++]-'0');
        if(result*sign >= 3.40282e+38) {
            return false;
        }
        if(result*sign <= -3.40282e+38) {
            return false;
        }
    }
    float j = 0.1;
    if((input[i] == '.' && (input[i-1] == '-' || input[i-1] == '+') && !('0' <= input[i+1] && input[i+1] <= '9')) || (input[i] == '.' && input[i+1] == '\0')) {
        return false;
    }
    if(input[i] == '.') {
        i++;
        while('0' <= input[i] && input[i] <= '9') {
            result = result + ((input[i++] - '0') * (j));
            j/=10;
        }
    }
    int po = 0, k = 0, signpo = 1;
    float p = 1;
    if((input[i] == 'e' || input[i] == 'E') && (input[i-1] == '.' || input[i+1] == '\0')) {
        return false;
    }
    if((input[i] == 'e' || input[i] == 'E') && i == 0) {
        return false;
    }
    if(input[i] == 'e' || input[i] == 'E') {
        i++;
        if(input[i] == '-' || input[i] == '+') signpo = (input[i++] == '-')? -1 : 1;
        while('0' <= input[i] && input[i] <= '9') {
            po = po*10 + (input[i++]-'0');
        }
        po = po * signpo;
        if(po > 0) {
            while(k < po) {
                p *= 10;
                k++;
            }
        }
        else {
            while(k > po) {
                p /= 10;
                k--;
            }
        }
    }
    result *= p;
    if(input[i] != '\0') {
        return false;
    }
    value = sign * result;
    return true;
}

#ifndef MARMOSET_TESTING
int main()
{
    char input[][100] = {"e1","123247932we","S","3.0000000000000000090384590384509843580938405895","","12.","12.e1","123","1e7","1.-1e-5","0.1e5","123.456","+.123456","+.123456e-9","+0.123456","-123.456","+123.456e+00007","+123.+7","123.456e7","-123.456e-7","-000123.456e0000","-.+", "+.","..","+.e9","+.e","+1.e-100","-123.-987e-3","-123.987e-3","-123.987e-3e4","0.00000000000000001357924681031415","13579246810314159265"};
    float value = 0;
    int size = sizeof(input)/sizeof(input[0]);
    for(int i = 0; i < size; i++) {
        if(stringToFloat(input[i], value)) {
            cout<<"the number is "<<input[i]<<" : "<<value<<endl;
        }
        else {
            cout<<"Error: "<<input[i]<<endl;
        }
    }

    return 0;
}
#endif
