// random_search.h
#ifndef RANDOM_SEARCH_H
#define RANDOM_SEARCH_H

#include <vector>
#include <random>
#include <iostream>

// Random search: checks elements in a random order
// Returns index if found, -1 otherwise
// steps counts the number of comparisons
template <typename T>
int randomSearch(const T *vec, size_t size, const T &target, int &steps)
{
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
        ++steps;
        size_t i = idx[k];
        if (vec[i] == target)
            return static_cast<int>(i);
    }

    return -1;
}

#endif