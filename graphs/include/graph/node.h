// node.h
#ifndef NODE_H
#define NODE_H

#include <unordered_set>

class Node
{
    friend class ListGraph;
    friend class MatrixGraph;

private:
    static int counter;
    int id;
    int data;
    std::unordered_set<Node *> neighbors;

public:
    Node(int data) : data(data), id(counter++) {};

    int getId() const { return id; }
    int getData() const { return data; }

    static void resetCounter() { counter = 0; };
};

#endif
