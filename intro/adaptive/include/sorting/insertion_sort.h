// insertion_sort.h
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

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
    for (size_t i = 1; i < size; ++i)
    {
        size_t j = i;

        // Keep bubbling vec[j] left while it's smaller than its predecessor
        while (j > 0)
        {
            // compare vec[j-1] and vec[j]
            ++steps;

            if (vec[j - 1] > vec[j])
            {
                std::swap(vec[j - 1], vec[j]);
                --j;
            }
            else
            {
                // exit if !(vec[j-1] > vec[j])
                break;
            }
        }
    }
    return;
}
#endif