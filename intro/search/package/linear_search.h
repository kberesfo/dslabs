// linear_search.h
#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <vector>
#include <iostream>

template <typename T>
int linearSearch(const T *vec, size_t size, const T &target, int &steps)
{
    // reset steps
    steps = 0;
    // iterate over vec
    for (size_t i = 0; i < size; ++i)
    {
        // increment steps
        ++steps;
        // if we find the target
        if (vec[i] == target)
        {
            // cast and return index
            return static_cast<int>(i);
        }
    }

    return -1;
}

#endif