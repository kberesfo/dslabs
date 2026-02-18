// bubble_sort.h
#ifndef FLAGGED_BUBBLE_SORT_H
#define FLAGGED_BUBBLE_SORT_H

#include <vector>

/// @brief Sorts the array in ascending order using flag bubble sort.
/// @tparam T Element type.
/// @param vec Pointer to the array to sort.
/// @param size Number of elements.
/// @param steps Counts the number of comparisons.
template <typename T>
void bubbleSort(T *vec, size_t size, int &steps)
{
    steps = 0;

    do
    {
        // reset flag
        bool swapped = false;
        for (int i = 0; i < size - 1; ++i)
        {
            ++steps;
            if (vec[i] > vec[i + 1])
            {
                std::swap(vec[i], vec[i + 1]);
                // if a swap occurs then the sort was required
                swapped = true;
            }
        }
    } while (swapped)

        return;
}

#endif