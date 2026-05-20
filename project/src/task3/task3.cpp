#include "task3/task3.hpp"

/// @brief we look for the lowest val we have see so far, then subtract the
/// @param v
/// @return
int task_3(std::vector<int> &v)
{
    if (v.empty())
        return 0;

    int curr_low = v[0];
    int curr_max = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        if (curr_low > v[i])
        {
            curr_low = v[i];
        }

        if ((v[i] - curr_low) > curr_max)
        {
            curr_max = v[i] - curr_low;
        }
    }

    return curr_max;
}