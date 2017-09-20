#include <stdlib.h>
#include <iostream>

using namespace std;

int main( const int argc, const char* const argv[])
{
    int first_num  = atoi(argv[1]); // datatype identifier = initialised value;
    int second_num  = atoi(argv[2]); // equals sign is also known as the assignment operator

    int sum = first_num + second_num;
    cout<<"sum: "<<sum<<endl; // we refernce our variable to call the

    int product= first_num * second_num;//https://msdn.microsoft.com/en-us/library/126fe14k.aspx
    cout<<"product: "<<product<<endl;
    //to skip lines use if else and to repeat use for loop

    return 0;

}
