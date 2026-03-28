// tree.h
#ifndef TREE_H
#define TREE_H

#include "node.h"

class Tree
{
private:
    int size = 0;
    Node *rootNode = nullptr;

public:
    Tree() {}
    ~Tree() { delete rootNode; }

    int find(int value, int &steps) const
    {
        Node *tmpNode = rootNode;
        steps = 0;

        while (tmpNode != nullptr)
        {
            ++steps;
            if (value == tmpNode->value)
            {
                return tmpNode->value;
            }
            else if (value < tmpNode->value)
            {
                tmpNode = tmpNode->leftNode;
            }
            else
            {
                tmpNode = tmpNode->rightNode;
            }
        }

        // return -1 if not found
        return -1;
    };

    void insert(int value)
    {
        Node *newNode = new Node(value);
        Node *currentNode = rootNode;

        // tree doesn't have root node yet
        if (rootNode == nullptr)
        {
            rootNode = newNode;
            return;
        }
        // iterate through the tree
        while (true)
        {
            // if the new value is less than current value go left node
            if (newNode->value < currentNode->value)
            {
                // if left node is null set left = to new node
                if (currentNode->leftNode == nullptr)
                {
                    currentNode->leftNode = newNode;
                    ++size;
                    return;
                }
                // move down the left side of the tree
                currentNode = currentNode->leftNode;
            }
            // else go to the right node
            else
            {
                // if right node is null set right node = to new node
                if (currentNode->rightNode == nullptr)
                {
                    currentNode->rightNode = newNode;
                    ++size;
                    return;
                }
                // move down the right side of the tree
                currentNode = currentNode->rightNode;
            }
        }
    };
};

#endif
