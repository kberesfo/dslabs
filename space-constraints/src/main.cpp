#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<unsigned int> &arr)
{
    unsigned int temp;
    
    for (unsigned int i = 0; i < arr.size() / 2; ++i)
    {
        temp = arr[i];
        arr[i] = arr[arr.size() - i - 1];
        arr[arr.size() - i - 1] = temp;
    }

    return;
}

int main()
{
    vector<unsigned int> arr = {1, 2, 3, 4, 5};

    reverse(arr);

    for (auto i : arr)
    {
        cout << i << "\n";
    }

    return 0;
}