#include <cmath>
#include <vector>
#include <iostream>

#include "package/random_search.h"
#include "package/linear_search.h"
#include "package/binary_search.h"

using namespace std;

int main()
{
    vector<int> sorted_vec{2, 4, 6, 8, 10, 12, 13};
    vector<int> big_vec(100000);
    // populate big_vec with indexes
    for (int i = 0; i < (int)big_vec.size(); ++i)
        big_vec[i] = i;

    int steps;
    int bin_search_worst = static_cast<int>(ceil(log2(100000)));
    int lin_search_worst = static_cast<int>(big_vec.size());

    cout << "Worst case number of steps linear search: " << lin_search_worst << "\n";
    cout << "Worst case number of steps binary search: " << bin_search_worst << "\n";

    cout << "Linear search idx: " << linearSearch(big_vec.data(), big_vec.size(), -1, steps)
         << " steps: " << steps << "\n";

    cout << "Binary search idx: " << binarySearch(big_vec.data(), big_vec.size(), 100000, steps)
         << " steps: " << steps << "\n";

    cout << "Random search idx: " << randomSearch(big_vec.data(), big_vec.size(), -1, steps)
         << " steps: " << steps << "\n";
    // flush
    cout << endl;

    return 0;
}