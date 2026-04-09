// node.h
#ifndef NODE_H
#define NODE_H

#include <vector>

class Node
{
    friend class GraphList;
    friend class GraphMatrix;

private:
    int id;
    int data;
    std::vector<Node *> neighbors;
    static int counter;

public:
    Node(int data) : data(data), id(counter++) {};
    
    int getId() const;
    int getData() const;

    static void resetCounter();
};

#endif
