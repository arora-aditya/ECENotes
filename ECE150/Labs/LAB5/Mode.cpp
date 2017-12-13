#include <iostream>
#include <stdio.h>
#include <limits>

using namespace std;

int range(const int dataset[], const int size){
    if(size == 0){
        return -1;
    }
    int max = -2147483648;
    int min = 2147483647;
    for(int i = 0; i < size; i++){
        if(dataset[i] < min){
            min = dataset[i];
        }
        if(dataset[i] > max){
            max = dataset[i];
        }
    }
    return max-min;
}

// Return minimum index
int minIndex(int a[], int i, int j)
{
    if (i == j)
        return i;

    // Find minimum of remaining elements
    int k = minIndex(a, i + 1, j);

    // Return minimum of current and remaining.
    return (a[i] < a[k])? i : k;
}

// Recursive selection sort. n is size of a[] and index
// is index of starting element.
void selection(int a[], int n, int index = 0)
{
    // Return when starting and size are same
    if (index == n)
       return;

    // calling minimum index function for minimum index
    int k = minIndex(a, index, n-1);

    // Swapping when index nd minimum index are not same
    if (k != index)
       swap(a[k], a[index]);

    // Recursively calling selection sort function
    selection(a, n, index + 1);
}

bool sort(int dataset[], const int size){
    selection(dataset, size);
    return true;
}

int mode(const int dataset[], const int size, int mode[]){
    int copy[size], uniqueDataset[size], count[size];
    for(int i = 0; i < size; i++){
        copy[i] = dataset[i];
    }
    sort(copy, size);
    int j = 0;
    uniqueDataset[j] = copy[0];
    count[j] = 0;
    int maxCount = -2147483648;
    for(int i = 0; i < size; i++){
        if(uniqueDataset[j] != copy[i]){
            j += 1;
            uniqueDataset[j] = copy[i];
            count[j] = 0;
        }
        count[j] += 1;
        if(maxCount < count[j]){
            maxCount = count[j];
        }
    }
    int k = 0;
    // for(int i = 0; i < j+1; i++){
    //     cout<<count[i]<<"  "<<uniqueDataset[i]<<endl;
    // }
    for(int i = 0; i < j + 1; i++){
        if(maxCount == count[i]){
            mode[k] = uniqueDataset[i];
            k++;
        }
    }
    return k;
}

#ifndef MARMOSET_TESTING

int main(const int argc, const char* const argv[]) {

  // Some test driver code here ....
  int data[] = {9998 , 9998 , 9996 , 9998 , 10000 , 9996 , 9996 , 9997 , 9996 , 9996 , 9999 , 9999 , 9996 , 9997 , 10000};
  int size = sizeof(data)/sizeof(data[0]);
  //change this to however many modes you expect to find
  int modeArray[100]={0};
  int rng = range(data, size);
  int modes = mode(data, size, modeArray);
  cout << "range: " << rng << " number of Modes: " << modes << " Modes are this: ";
  for(int i = 0; i<modes;i++){
  	cout<< modeArray[i];
  	if(i<modes-1){
  		cout << ", ";
  	}
  }
  cout<<endl;
  return 0;
}

#endif
