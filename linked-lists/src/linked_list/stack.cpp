#include <ostream>
#include <stdexcept>

#include "linked_list/linked_list.h"

Stack::Stack()
{
    top = nullptr;
    size = 0;
}

bool Stack::isEmpty()
{
    if (top == nullptr)
    {
        return true;
    }

    return false;
}

int Stack::peek()
{
    if (isEmpty())
    {
        return -1;
    }

    return top->data;
}

int Stack::pop()
{

    if (isEmpty())
    {
        return -1;
    }

    Node *temp = top;
    top = top->next;
    int val = temp->data;

    delete temp;
    return val;
}

void Stack::push(int value)
{
    Node *temp = new Node{value, nullptr};
    temp->next = top;
    top = temp;
}

std::ostream &operator<<(std::ostream &os, const Stack &stack)
{
    Node *currentNode = stack.top;

    while (currentNode->next != nullptr)
    {
        os << "[ " << currentNode->data << " | *" << " ],";
        currentNode = currentNode->next;
    }

    os << "[ " << currentNode->data << " | nullptr" << " ]";
}