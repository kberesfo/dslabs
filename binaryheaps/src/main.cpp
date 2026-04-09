#include <iostream>

#include "heap/max_heap.h"

using namespace std;

int main()
{
    // Task 3: Insert 55,22,34,10,2,99,68 then pop all out
    cout << "\n--- Task 3: Pop order of 55,22,34,10,2,99,68 ---" << endl;
    MaxHeap heap;
    for (int val : {55, 22, 34, 10, 2, 99, 68})
        heap.insert(val);
    cout << "Heap: " << heap << endl;
    cout << "Pop order: ";
    while (!heap.isEmpty())
        cout << heap.pop() << " ";
    cout << endl;

    return 0;
}
