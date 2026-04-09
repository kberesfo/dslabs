// heap.h

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

class Heap
{
private:
    std::vector<int> data;

    int parent(int i) const { return (i - 1) / 2; }
    int left(int i) const { return (2 * i) + 1; }
    int right(int i) const { return (2 * i) + 2; }

    void bubbleUp(int i);
    void bubbleDown(int i);

protected:
    virtual bool compare(int a, int b) const = 0;

public:
    Heap() {}
    ~Heap() {}

    void insert(int value);
    int pop();
    int peek() const;
    bool isEmpty() const;
    int getSize() const;

    friend std::ostream &operator<<(std::ostream &os, const Heap &hp);
};

#endif
