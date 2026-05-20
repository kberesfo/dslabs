#include "task6/task6.hpp"

/// @brief This uses a set for every number in the array, if the num-1 exists in  the set then its not the head of the sequence. we can iterate over the set count the length of the longest sequence using the heads of each series.
/// @param v a vector of ints
/// @return length of the longest sequence.
int task_6(std::vector<int> &v)
{
    std::unordered_set<int> num_set(v.begin(), v.end());
    int longestStreak = 0;

    for (int num : num_set)
    {
        if (!num_set.count(num - 1))
        {
            int currentNum = num;
            int currentStreak = 1;
            while (num_set.count(currentNum + 1))
            {
                currentNum += 1;
                currentStreak += 1;
            }
            longestStreak = std::max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}