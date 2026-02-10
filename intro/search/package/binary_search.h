// binary_search.h
#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>
#include <iostream>

template <typename T>
int binarySearch(const T *vec, size_t size, const T &target, int &steps)
{
    steps = 0;
    if (size == 0)
        return -1;

    int left = 0;
    int right = static_cast<int>(size) - 1;

    while (left <= right)
    {
        ++steps;
        int mid = left + (right - left) / 2;
        // if vec[mid] == target return the target
        if (vec[mid] == target)
            // cast and return index
            return static_cast<int>(mid);
        else if (vec[mid] < target)
            // if the target is larger than vec[mid] update left
            left = mid + 1;
        else
            // if the target is less than vec[mid] update the right
            right = mid - 1;
    }

    return -1;
}

#endif