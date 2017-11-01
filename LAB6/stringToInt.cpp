//
//  stringToInt.cpp
//  ECE150
//
//  Created by Aditya Arora on 2017-10-31.
//
// what to do when result > INT_MAX or < INT_MIN

#include <iostream>
#include <limits>
using namespace std;

bool stringToInt(const char input[], int& value){
	int result = 0;
    int sign = 1;
	int i = 0;
	if(input[i] == '-' || input[i] == '+') sign = (input[i++] == '-')? -1 : 1;
	while('0' <= input[i] && input[i] <= '9'){
		result = result*10 + (input[i++]-'0');
        if(result*sign >= INT_MAX){
			value = INT_MAX;
			break;
		}
        if(result*sign <= INT_MIN){
			value = INT_MIN;
			break;
		}
	}
	if(input[i] != '\0'){
		return false;
	}
	value = sign * result;
	return true;
}


int main()
{	int value = -2;
	cout<<stringToInt("-123343234234", value)<<endl;
	cout<<value<<endl;
	return 0;
}
