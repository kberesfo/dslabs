// max_heap.h

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "heap/heap.h"

class MaxHeap : public Heap
{
protected:
    bool compare(int a, int b) const override;
};

#endif
