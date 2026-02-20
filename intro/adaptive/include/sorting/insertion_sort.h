// insertion_sort.h
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <vector>

/// @brief Sorts the array in ascending order using insertion sort.
/// @tparam T Element type.
/// @param vec Pointer to the array to sort.
/// @param size Number of elements.
/// @param steps Counts the number of comparisons.
template <typename T>
void insertionSort(T *vec, size_t size, int &steps)
{
    // reset steps
    steps = 0;

    for (int i = 1; i < size; ++i)
    {
        for (int j = i; j > 0; --j)
        {
            ++steps;
            if (vec[j] < vec[j - 1])
                std::swap(vec[j], vec[j - 1]);
            else
                break;
        }
    }
    return;
}
#endif