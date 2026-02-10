// linear_search.h
#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <vector>
#include <iostream>

template <typename T>
int linearSearch(const T *vec, size_t size, const T &target, int &steps)
{
    steps = 0;
    for (size_t i = 0; i < size; ++i)
    {
        ++steps;

        if (vec[i] == target)
        {
            return static_cast<int>(i);
        }
    }

    return -1;
}

#endif