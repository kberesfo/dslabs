// linear_search.h
#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <vector>
#include <iostream>

/// @brief Performs a linear search for a target value in an array.
/// @tparam T Type of elements stored in the array.
/// @param vec Pointer to the array to search.
/// @param size Number of elements in the array.
/// @param target Value to search for.
/// @param steps Output parameter that records the number of comparisons performed.
/// @return Index of the target if found; -1 if the target is not present.
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