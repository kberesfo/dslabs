// task1.hpp
#ifndef TASK_1_H
#define TASK_1_H

#include <vector>
#include <string>

struct Player
{
    std::string first_name;
    std::string last_name;
    std::string team;
};

std::vector<std::string> task_1(
    const std::vector<Player> &a,
    const std::vector<Player> &b);

#endif