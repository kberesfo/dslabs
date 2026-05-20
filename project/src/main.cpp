#include <iostream>
#include <vector>

#include "task1/task1.hpp"
#include "task2/task2.hpp"
#include "task3/task3.hpp"
#include "task4/task4.hpp"
#include "task5/task5.hpp"
#include "task6/task6.hpp"

using namespace std;

void print_string_vec(const vector<string> &items)
{
    for (const auto &item : items)
        cout << item << ", ";
    cout << "\n";
}

void print_vec(const vector<double> &vec)
{
    cout << "{ ";
    for (auto v : vec)
        cout << v << ",";
    cout << "}\n";
}

int main()
{
    vector<Player> basketball_players = {
        {first_name : "Jill", last_name : "Huang", team : "Gators"},
        {first_name : "Janko", last_name : "Barton", team : "Sharks"},
        {first_name : "Wanda", last_name : "Vakulskas", team : "Sharks"},
        {first_name : "Jill", last_name : "Moloney", team : "Gators"},
        {first_name : "Luuk", last_name : "Watkins", team : "Gators"}};
    vector<Player> football_players = {
        {first_name : "Hanzla", last_name : "Radosti", team : "32ers"},
        {first_name : "Tina", last_name : "Watkins", team : "Barleycorns"},
        {first_name : "Alex", last_name : "Patel", team : "32ers"},
        {first_name : "Jill", last_name : "Huang", team : "Barleycorns"},
        {first_name : "Wanda", last_name : "Vakulskas", team : "Barleycorns"}};

    vector<int> task_2_vec = {8, 2, 3, 9, 4, 7, 5, 0, 6};
    vector<int> task_3_vec = {10, 7, 5, 8, 11, 2, 6};
    vector<int> task_4_vec = {5, -10, -6, 9, 4};
    vector<double> task_5_vec = {98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1};
    vector<int> task_6_vec = {19, 13, 15, 12, 18, 14, 17, 11};

    print_string_vec(task_1(basketball_players, football_players));

    cout << task_2(task_2_vec) << "\n";
    cout << task_3(task_3_vec) << "\n";
    cout << task_4(task_4_vec) << "\n";

    task_5(99.0, 97.0, task_5_vec);
    print_vec(task_5_vec);

    cout << task_6(task_6_vec) << "\n";

    return 0;
}