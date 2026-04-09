// tree.h
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>

#include "bst/node.h"

class BinaryTree
{
private:
    int size = 0;
    Node *rootNode = nullptr;

    void preOrder(Node *node, std::ostream &out) const;
    void postOrder(Node *node, std::ostream &out) const;
    void inOrder(Node *node, std::ostream &out) const;


public:
    BinaryTree() {}
    ~BinaryTree() { delete rootNode; }

    int find(int value, int &steps) const;

    void insert(int value);
    /// @brief This is a public method that kicks off the pre-order traversal
    void preOrder(std::ostream &out) const { preOrder(rootNode, out); }
    /// @brief This is a public method that kicks off the post-order traversal
    void postOrder(std::ostream &out) const { postOrder(rootNode, out); }
    /// @brief This is a public method that kicks off the in-order traversal
    /// @param out ostream object to simulate doing work
    void inOrder(std::ostream &out) const { inOrder(rootNode, out); }
    /// @brief
    /// @param out ostream object to sim doing work
    void levelOrder(std::ostream &out) const;
};

#endif
