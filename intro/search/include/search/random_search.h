// random_search.h
#ifndef RANDOM_SEARCH_H
#define RANDOM_SEARCH_H

#include <vector>
#include <random>

/// @brief Performs a random search for a target value in an array.
/// @tparam T Type of elements stored in the array.
/// @param vec Pointer to the array to search.
/// @param size Number of elements in the array.
/// @param target Value to search for.
/// @param steps Output parameter that records the number of comparisons performed.
/// @return Index of the target if found; -1 if the target is not present.
template <typename T>
int randomSearch(const T *vec, size_t size, const T &target, int &steps)
{
    // reset steps
    steps = 0;
    if (size == 0)
        return -1;

    // create an array of indexes 0..size-1
    std::vector<size_t> idx(size);
    for (size_t i = 0; i < size; ++i)
        idx[i] = i;

    // shuffle indices (Fisher–Yates)
    std::random_device rd;
    std::mt19937 gen(rd());
    // iterate over the array backwards
    for (size_t i = size - 1; i > 0; --i)
    {
        // create a distribution between 0 and i
        std::uniform_int_distribution<size_t> dist(0, i);
        // pick a second index to shuffle with
        size_t j = dist(gen);
        // swap arr[j] and arr[i] using tmp bucket
        size_t tmp = idx[i];
        idx[i] = idx[j];
        idx[j] = tmp;
    }

    // preform linear search using shuffled indexes
    for (size_t k = 0; k < size; ++k)
    {
        // increment steps
        ++steps;
        // get the index from shuffled indexes
        size_t i = idx[k];
        // check if vec[i] is target
        if (vec[i] == target)
            return static_cast<int>(i);
    }

    return -1;
}

#endif