#include "heap/heap.h"

std::ostream &operator<<(std::ostream &os, const Heap &hp)
{
    for (auto el: hp.data)
    {
        os << el << " ";
    }
    return os;
}

void Heap::insert(int value)
{
    data.push_back(value);
    bubbleUp(data.size() - 1);
}

int Heap::pop()
{
    int root = data[0];
    // get last element of vec
    data[0] = data.back();
    // remove last element of vec
    data.pop_back();
    // bubble the elements down
    bubbleDown(0);
    // return the value that was at root
    return root;
}

int Heap::peek() const
{
    return data[0];
}

bool Heap::isEmpty() const
{
    return data.empty();
}

int Heap::getSize() const
{
    return data.size();
}

void Heap::bubbleUp(int i)
{

    // don't exit the tree but compare target and parent
    while (i > 0 && compare(data[i], data[parent(i)]))
    {
        // swap if compare returns true
        std::swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

void Heap::bubbleDown(int i)
{
    int size = data.size();
    int target = i;
    // don't go out of bounds and compare left to target
    if (left(i) < size && compare(data[left(i)], data[target]))
        target = left(i);
    // don't go out of bounds and compare right to target
    if (right(i) < size && compare(data[right(i)], data[target]))
        target = right(i);

    if (target != i)
    {
        std::swap(data[i], data[target]);
        bubbleDown(target);
    }
}


