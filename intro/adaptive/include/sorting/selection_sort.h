// selection_sort.h
#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <vector>

/// @brief Sorts the array in ascending order using selection sort.
/// @tparam T Element type.
/// @param vec Pointer to the array to sort.
/// @param size Number of elements.
/// @param steps Counts the number of comparisons.
template <typename T>
void selectionSort(T *vec, size_t size, int &steps)
{
    // reset steps
    steps = 0;
    for (int i = 0; i < size; ++i)
    {
        // assume vec[i] is the min value and min_index = i
        size_t min_index = i;
        // iterate over the array from i to vec[end]
        for (int j = i + 1; j < size; ++j)
        {
            ++steps;
            // if we find another min value
            if (vec[min_index] > vec[j])
            {
                // update the min index
                min_index = j;
            }
        }

        if (min_index != i)
        {
            std::swap(vec[i], vec[min_index]);
        }
    }
    return;
}

#endif