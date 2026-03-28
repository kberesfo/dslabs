#include <vector>
#include <iostream>

#include "bst/bst.h"

using namespace std;

int main()
{
    vector<int> inputVec{1, 5, 9, 2, 4, 10, 6, 3, 8};
    Tree tree = Tree();
    int steps = 0;

    for (int i = 0; i < inputVec.size(); ++i)
    {
        tree.insert(inputVec[i]);
    }

    tree.find(10, steps);
    cout << "It took: " << steps << " steps to find 10\n";
    tree.find(40, steps);
    cout << "It took: " << steps << " steps to search for 40\n\n";

    return 0;
}