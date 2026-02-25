// classify_sort_case.h
#ifndef CLASSIFY_SORT_CASE_H
#define CLASSIFY_SORT_CASE_H

#include <cstddef>
#include <ostream>

enum class CaseEnum
{
    Best,
    Average,
    Worst
};

// overload << to print enum
inline std::ostream &operator<<(std::ostream &os, CaseEnum c)
{
    switch (c)
    {
    case CaseEnum::Best:
        os << "Best";
        break;
    case CaseEnum::Average:
        os << "Average";
        break;
    case CaseEnum::Worst:
        os << "Worst";
        break;
    }
    return os;
}

/// @brief Classifies the initial ordering of an array as Best, Average, or Worst case
///        based on the percentage of adjacent out-of-order elements.
///
/// The function analyzes the array without performing any sorting.
/// It counts how many adjacent pairs (vec[i-1], vec[i]) are out of ascending order.
/// The percentage of such pairs is used to determine classification:
/// - ≤ 10% out of order → Best case (nearly sorted)
/// - ≥ 65% out of order → Worst case (nearly reverse sorted)
/// - Otherwise → Average case
///
/// @tparam T Element type.
/// @param vec Pointer to the array to classify
/// @param size Number of elements in the array
/// @return CaseEnum representing Best, Average, or Worst case
///
/// @complexity O(n)
template <typename T>
CaseEnum classifySortCase(const T *vec, size_t size)
{
    // init counter
    int bad_adj = 0;
    for (size_t i = 1; i < size; ++i)
    {
        // if left > right increment counter
        if (vec[i] < vec[i - 1])
            ++bad_adj;
    }

    const double total_adj = static_cast<double>(size - 1);
    const double bad_percent = (static_cast<double>(bad_adj) / total_adj) * 100.0;
    // 10% or less of the array is out of order
    if (bad_percent <= 10)
        return CaseEnum::Best;
    // 65% or more of the array is out of order
    if (bad_percent >= 65)
        return CaseEnum::Worst;
    // else avg
    return CaseEnum::Average;
}

#endif