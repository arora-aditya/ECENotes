//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <limits>
#include <stdio.h>
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
// #defines, enum, and function declarations; do not remove
//

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself
#define NaN std::numeric_limits<float>::quiet_NaN() // (comes from <limits>)

enum sortType { ASCENDING, DESCENDING, UNKNOWN, UNSORTED };

bool isSorted(const float data[], const int currentDataItem, const sortType typeOfSort);
bool sorted(const float data[]);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
//


bool isSorted(const float data[], const int currentDataItem, const sortType typeOfSort) {
    if(isNaN(data[currentDataItem]) || typeOfSort == UNSORTED){
        switch(typeOfSort){
            case ASCENDING:
            case DESCENDING:
            case UNKNOWN: return true; break;
            case UNSORTED: return false; break;
        }

    }
    if(typeOfSort == UNKNOWN){
        if(data[currentDataItem] < data[currentDataItem + 1]){
            return isSorted(data, currentDataItem + 1, ASCENDING);
        }
        else if(data[currentDataItem] > data[currentDataItem + 1]){
            return isSorted(data, currentDataItem + 1, DESCENDING);
        }
        else{
            return isSorted(data, currentDataItem + 1, UNKNOWN);
        }
    }
    else{
        switch(typeOfSort){
            case ASCENDING:
                if(data[currentDataItem] >= data[currentDataItem-1]){
                    return isSorted(data, currentDataItem + 1, typeOfSort);
                }
                else{
                    return isSorted(data, currentDataItem + 1, UNSORTED);
                }
                break;
            case DESCENDING:
                if(data[currentDataItem] <= data[currentDataItem-1]){
                    return isSorted(data, currentDataItem + 1, typeOfSort);
                }
                else{
                    return isSorted(data, currentDataItem + 1, UNSORTED);
                }
                break;
            case UNKNOWN: return isSorted(data, currentDataItem + 1, UNKNOWN); break;
            case UNSORTED: return false; break;
        }
    }
    // bool sortAscending = true;
    // for(int i = 0; !isNaN(data[i]); i++){
    //     if(data[i] > data[i+1]){
    //         sortAscending = false;
    //         break;
    //     }
    // }
    // bool sortDescending = true;
    // for(int i = 0; !isNaN(data[i]); i++){
    //     if(data[i] < data[i+1]){
    //         sortDescending = false;
    //         break;
    //     }
    // }
    // return sortAscending || sortDescending;
}

bool sorted(const float data[]) {
    if(isNaN(data[0])){
        return true;
    }
    return isSorted(data, 0,UNKNOWN);
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

  // Some test driver code here ....
  float data[] = {1, 2, 4, 5, 9, NaN};
  float data1[] = {NaN};
  if (sorted(data1))
    cout << "Data is sorted" << endl;
  else
    cout << "Data is not sorted" << endl;

  return 0;
}

#endif
