#include <iostream>

using namespace std;

/// @brief Question 3 implementation
/// @param low - lower bound int
/// @param high - upper bound int
/// @return sum of all the numbers between and including uper and lower bound
int sum(int low, int high)
{
    if (low == high)
        return low;

    return high + sum(low, high - 1);
}



int main()
{

    cout << sum(10, 15) << "\n";
    return 0;
}