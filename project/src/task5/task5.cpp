#include "task5/task5.hpp"

void task_5(double max, double min, std::vector<double> &v)
{
    std::vector<int> counter;
    counter.resize((int)((max - min) * 10) + 1, 0);

    for (double i : v)
    {
        counter[(int)(i * 10) - (int)(min * 10)] += 1;
    }

    int v_index = 0;
    for (int i = 0; i < counter.size(); ++i)
    {
        for (int j = 0; j < counter[i]; ++j)
        {
            v[v_index] = (double)(i + (int)(min * 10)) / 10.0;
            ++v_index;
        }
    }
}