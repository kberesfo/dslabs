// min_heap.h

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "heap/heap.h"

class MinHeap : public Heap
{
protected:
    bool compare(int a, int b) const override;
};

#endif
