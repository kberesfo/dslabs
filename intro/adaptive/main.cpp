#include <vector>
#include <iostream>
#include <random>

#include "sorting/sorting.h" // bubbleSort, selectionSort, insertionSort
#include "classifiers/classify_sort_case.h"
#include "util/print_vec.h"

using namespace std;

static void partA(ostream &out_stream)
{
    // init vec of len 50
    vector<int> original(50);
    // init steps
    int steps = 0;

    // random number gen
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 100);
    // for each randomly generate a value add it to the array
    for (int &value : original)
    {
        value = dist(gen);
    }

    // print array
    out_stream << "Original array: ";
    printVec(original.data(), original.size(), out_stream);
    out_stream << "\n";
    // classify the sort case
    CaseEnum vec_sort_case = classifySortCase(original.data(), original.size());

    out_stream << "Case:  " << vec_sort_case << "\n";

    // create a copy
    vector<int> sorted_vec = original;

    if (vec_sort_case == CaseEnum::Best)
    {
        insertionSort(sorted_vec.data(), sorted_vec.size(), steps);
        out_stream << "Insertion sorted: ";
        printVec(sorted_vec.data(), sorted_vec.size(), out_stream);
        out_stream << "Insertion steps:  " << steps << "\n\n";
    }
    else
    {
        selectionSort(sorted_vec.data(), sorted_vec.size(), steps);
        out_stream << "Selection sorted: ";
        printVec(sorted_vec.data(), sorted_vec.size(), out_stream);
        out_stream << "Selection steps:  " << steps << "\n\n";
    }
}

static void partB(istream &in_stream, ostream &out_stream)
{
    vector<int> original(50);
    // prompt for ints
    out_stream << "Enter 50 integers:\n";
    // for each value in original get a new value
    for (int &value : original)
    {
        // wait for user input, if its not a number
        while (!(in_stream >> value))
        {
            // let user know it was invalid input
            out_stream << "Invalid input. Please enter an integer: ";
            // clear error
            in_stream.clear();
            // reset buffer
            in_stream.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    CaseEnum vec_sort_case = classifySortCase(original.data(), original.size());
    // overwrite best for avg
    if (vec_sort_case == CaseEnum::Best)
        vec_sort_case = CaseEnum::Average;

    out_stream << "Classification (Part B): " << vec_sort_case << "\n";
    printVec(original.data(), original.size(), out_stream);
}

int main()
{
    partA(cout);
    partB(cin, cout);

    return 0;
}
