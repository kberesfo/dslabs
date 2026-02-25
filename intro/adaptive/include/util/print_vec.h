// print_vec.h
#ifndef PRINT_VEC_H
#define PRINT_VEC_H

#include <cstddef>
#include <ostream>

/// @brief Prints a vector or array to console
/// @tparam T Element type.
/// @param vec Pointer to the array to print.
/// @param size Number of elements.
/// @param out_stream
template <typename T>
void printVec(const T *vec, size_t size, std::ostream &out_stream)
{
    // for each loop
    for (size_t i = 0; i < size; ++i)
        out_stream << vec[i] << " ";
    out_stream << "\n";
}

#endif