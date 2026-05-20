#include "task4/task4.hpp"

int task_4(std::vector<int> &v)
{
    if (v.size() < 2)
        return 0;

    int highest = std::max(v[0], v[1]);
    int second_highest = std::min(v[0], v[1]);
    
    int lowest = std::min(v[0], v[1]);
    int second_lowest = std::max(v[0], v[1]);

    for (auto i = 2; i < v.size(); ++i)
    {
        if (v[i] >= highest)
        {
            second_highest = highest;
            highest = v[i];
        }
        else if (v[i] > second_highest)
        {
            second_highest = v[i];
        }

        if (v[i] <= lowest)
        {
            second_lowest = lowest;
            lowest = v[i];
        }
        else if (v[i] < second_lowest)
        {
            second_lowest = v[i];
        }
    }

    return std::max(highest * second_highest, lowest * second_lowest);
}