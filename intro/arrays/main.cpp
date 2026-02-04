#include <iostream>

using namespace std;

int main()
{
    // create an array of 100 elements.
    int arr[100];
    // print to the console the size allocated  for each element.
    cout << "Size of each element: " << sizeof(arr[0]) << "\n";
    // print to  the console the mem addr of arr
    cout << "Address of the base of the array: " << arr << "\n";
    // print the mem addr of arr[0] and flush
    cout << "Address of first element: " << &arr[0] << endl;

    return 0;
}