#include "task2/task2.hpp"

/// @brief since the series starts at 0 we can calc the sum from 0-N by doing N*(N+1)/2. since we know the sum of all the elements is will be off by the missing number, so we can subtract the vec sum from the theory sum to find the missing number.
/// @param v vector of ints.
/// @return the missing number.
int task_2(std::vector<int> &v)
{
    unsigned int n = v.size();
    unsigned int theory_sum = n * (n + 1) / 2;
    int vec_sum = 0;

    for (auto num : v)
    {
        vec_sum += num;
    }

    return theory_sum - vec_sum;
}