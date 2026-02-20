// bubble_sort.h
#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <vector>

/// @brief Sorts the array in ascending order using bubble sort.
/// @tparam T Element type.
/// @param vec Pointer to the array to sort.
/// @param size Number of elements.
/// @param steps Counts the number of comparisons.
template <typename T>
void bubbleSort(T *vec, size_t size, int &steps)
{
    // reset steps
    steps = 0;
    // iterate over the array
    for (int i = 0; i < size; ++i)
    {
        // size-1 prevents out of bounds
        for (int j = 0; j < size - 1; ++j)
        {
            ++steps;
            if (vec[j] > vec[j + 1])
            {
                // if left is bigger than right swap
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }

    return;
}

#endif