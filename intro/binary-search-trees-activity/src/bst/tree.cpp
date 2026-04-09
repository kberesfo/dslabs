
#include "bst/tree.h"

int BinaryTree::find(int value, int &steps) const
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

void BinaryTree::insert(int value)
{
    Node *newNode = new Node(value);
    Node *currentNode = rootNode;

    // tree doesn't have root node yet
    if (rootNode == nullptr)
    {
        rootNode = newNode;
        ++size;
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

void BinaryTree::preOrder(Node *node, std::ostream &out) const
{
    /*
    recursive base case:
    if node == nullptr return
    */
    if (node == nullptr)
        return;

    // do work
    out << node->value << "\n";

    // call on left node
    preOrder(node->leftNode, out);
    // call on right node
    preOrder(node->rightNode, out);
};

void BinaryTree::postOrder(Node *node, std::ostream &out) const
{
    /*
    recursive base case:
    if node == nullptr return
    */
    if (node == nullptr)
        return;
    // call on left node
    postOrder(node->leftNode, out);
    // call on right node
    postOrder(node->rightNode, out);

    // do work
    out << node->value << "\n";
};

void BinaryTree::inOrder(Node *node, std::ostream &out) const
{
    /*
    recursive base case:
    if node == nullptr return
    */
    if (node == nullptr)
        return;

    // call on left node
    inOrder(node->leftNode, out);

    // do work
    out << node->value << "\n";
    // call on right node
    inOrder(node->rightNode, out);
};

void BinaryTree::levelOrder(std::ostream &out) const
{
    // prevent null root node
    if (rootNode == nullptr)
        return;

    std::queue<Node *> q;
    q.push(rootNode);

    while (!q.empty())
    {
        // get the item off the queue
        Node *current = q.front();
        // remove the item from the queue
        q.pop();

        out << current->value << "\n";
        // push left node
        if (current->leftNode != nullptr)
            q.push(current->leftNode);
        // push right node
        if (current->rightNode != nullptr)
            q.push(current->rightNode);
    }
};