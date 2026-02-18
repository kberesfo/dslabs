// flagged_bubble_sort.h
#ifndef FLAGGED_BUBBLE_SORT_H
#define FLAGGED_BUBBLE_SORT_H

#include <vector>

/// @brief Sorts the array in ascending order using flag bubble sort.
/// @tparam T Element type.
/// @param vec Pointer to the array to sort.
/// @param size Number of elements.
/// @param steps Counts the number of comparisons.
template <typename T>
void flaggedBubbleSort(T *vec, size_t size, int &steps)
{
    // reset steps
    steps = 0;
    // declare flag in scope of while
    bool swapped = false;
    do
    {
        // reset flag
        swapped = false;
        // iterate over array
        for (size_t i = 0; i < size - 1; ++i)
        {
            // increment steps
            ++steps;
            // check if left > right
            if (vec[i] > vec[i + 1])
            {
                std::swap(vec[i], vec[i + 1]);
                // if a swap occurs then the sort was required
                swapped = true;
            }
        }
    } while (swapped);
    // exit function
    return;
}

#endif