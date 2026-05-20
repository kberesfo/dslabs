#include "task1/task1.hpp"

#include <unordered_set>

std::string build_name(const Player &p)
{
    std::string name = "";
    name += p.first_name;
    name += " ";
    name += p.last_name;

    return name;
}

/// @brief this method iterates over an creates a hash array. then if the array contains an element already it pushes the duplicate elemnet to the return vector
/// @param a
/// @param b
/// @return
std::vector<std::string> task_1(
    const std::vector<Player> &a,
    const std::vector<Player> &b)
{
    std::vector<std::string> ret;
    // increase the size of the hash_table to decrease collision chance
    std::unordered_set<std::string> ps;
    ps.reserve(a.size());

    for (const auto &p : a)
    {
        std::string name = build_name(p);

        ps.insert(name);
    }

    for (const auto &p : b)
    {
        std::string name = build_name(p);

        if (ps.count(name))
        {
            ret.push_back(name);
        }
    }

    return ret;
}
