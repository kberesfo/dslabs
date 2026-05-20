#include "task4/task4.hpp"

int task_4(std::vector<int> &v)
{
    if (!v.size())
        return 0;

    int largest_pos = std::max(v[0], v[1]);
    int second_pos = std::min(v[0], v[1]);

    int smallest_neg = std::min(v[0], v[1]);
    int second_neg = std::max(v[0], v[1]);

    for (auto i : v)
    {
        if (i > 0)
        {
            if (largest_pos < i)
            {
                second_pos = largest_pos;
                largest_pos = i;
            }
            else if (second_pos < i)
            {
                second_pos = i;
            }
        }
        else
        {
            if (smallest_neg > i)
            {
                second_neg = smallest_neg;
                smallest_neg = i;
            }
            else if (second_neg > i)
            {
                second_neg = i;
            }
        }
    }

    return (largest_pos * second_pos > smallest_neg * second_neg) ? largest_pos * second_pos : smallest_neg * second_neg;
}