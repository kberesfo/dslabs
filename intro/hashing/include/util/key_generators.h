// include/utils/key_generators.h
#ifndef KEY_GENERATORS_H
#define KEY_GENERATORS_H

#include <vector>
#include <string>
#include <random>

inline std::string makeRandomString(std::mt19937 &rng,
                                    int minLen = 5,
                                    int maxLen = 12)
{
    std::uniform_int_distribution<int> lenDist(minLen, maxLen);
    std::uniform_int_distribution<int> chDist('a', 'z');

    int len = lenDist(rng);
    std::string s;
    s.reserve(len);

    for (int i = 0; i < len; ++i)
        s.push_back(static_cast<char>(chDist(rng)));

    return s;
}

/// @brief
/// @param n
/// @param seed
/// @return
inline std::vector<std::string> makeRandomKeys(int n, unsigned seed = 123)
{
    std::mt19937 rng(seed);
    std::vector<std::string> keys;
    keys.reserve(n);

    for (int i = 0; i < n; ++i)
        keys.push_back(makeRandomString(rng));

    return keys;
}

/// @brief
/// @param n
/// @return
inline std::vector<std::string> makeStudentKeys(int n)
{
    std::vector<std::string> keys;
    keys.reserve(n);

    for (int i = 1; i <= n; ++i)
        keys.push_back("student" + std::to_string(i));

    return keys;
}

/// @brief
/// @param n
/// @return
inline std::vector<std::string> makeDataKeys(int n)
{
    std::vector<std::string> keys;
    keys.reserve(n);

    for (int i = 1; i <= n; ++i)
    {
        std::string s = "data_";
        if (i < 10)
            s += "000";
        else if (i < 100)
            s += "00";
        else if (i < 1000)
            s += "0";
        s += std::to_string(i);

        keys.push_back(s);
    }

    return keys;
}

#endif