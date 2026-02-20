#include <vector>
#include <iostream>

#include "sorting/sorting.h" // bubbleSort, selectionSort, insertionSort

using namespace std;

static void printVec(const vector<int> &v, std::ostream &out_stream)
{
    // for each loop
    for (int x : v)
        out_stream << x << " ";
    out_stream << "\n";
}

int main()
{
    // reverse-sorted is worst case for bubble and insertion
    vector<int> original{15, 14, 13, 12, 10, 8, 6, 4, 2, 1};

    const int n = static_cast<int>(original.size());
    const int theoretical_worst = n * (n - 1); // simple upper bound

    cout << "Theoretical Worst O(N^2): " << theoretical_worst << "\n";
    cout << "Original array: ";
    printVec(original, cout);
    cout << "\n";

    int steps = 0;

    // Bubble Sort
    vector<int> bubbleVec = original;
    bubbleSort(bubbleVec.data(), bubbleVec.size(), steps);
    cout << "Bubble sorted:   ";
    printVec(bubbleVec, cout);
    cout << "Bubble steps:    " << steps << "\n\n";

    // Selection Sort
    vector<int> selectionVec = original;
    selectionSort(selectionVec.data(), selectionVec.size(), steps);
    cout << "Selection sorted: ";
    printVec(selectionVec, cout);
    cout << "Selection steps:  " << steps << "\n\n";

    // Insertion Sort
    vector<int> insertionVec = original;
    insertionSort(insertionVec.data(), insertionVec.size(), steps);
    cout << "Insertion sorted: ";
    printVec(insertionVec, cout);
    cout << "Insertion steps:  " << steps << "\n\n";


    return 0;
}
