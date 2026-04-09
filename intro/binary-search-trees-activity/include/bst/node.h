// NODE.h
#ifndef NODE_H
#define NODE_H

class Node
{
    friend class BinaryTree;

private:
    Node *leftNode = nullptr;
    Node *rightNode = nullptr;
    int value;
    Node(int value) : value{value} {}
    ~Node() { delete leftNode; delete rightNode; }
};

#endif