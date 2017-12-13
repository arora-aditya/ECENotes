//
//  stringToInt.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-10-31.
//
// what to do when result > INT_MAX or < INT_MIN

#include <iostream>
using namespace std;

bool stringToInt(const char input[], int& value){
	long result = 0;
    int sign = 1;
	int i = 0;
	if(input[i] == '-' || input[i] == '+') sign = (input[i++] == '-')? -1 : 1;
	while('0' <= input[i] && input[i] <= '9'){
		result = result*10 + (input[i++]-'0');
        if(result*sign >= 2147483647){
			return false;
		}
        if(result*sign <= -2147483648){
			return false;
		}
	}
	if(input[i] != '\0'){
		return false;
	}
	value = sign * result;
	return true;
}

#ifndef MARMOSET_TESTING

int main()
{	int value = -2;
	cout<<stringToInt("-2147483647", value)<<endl;
	cout<<value<<endl;
	return 0;
}

#endif
