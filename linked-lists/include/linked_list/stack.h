// stack.h
#ifndef STACK_H
#define STACK_H

#include <ostream>
#include <stdexcept>

#include "node.h"

template <typename T>
class Stack
{
private:
    Node<T> *top;
    // added to track size of list
    int size;

public:
    Stack();

    /// @brief add a new value to the stack
    /// @param value the value to add
    /// @example Before push(40)
    /// Top → 30 → 20 → 10
    /// After push(40)
    /// Top → 40 → 30 → 20 → 10
    void push(T value);

    /// @brief remove a value from the list
    /// @return the next value int the stack
    /// @example Before pop()
    /// Top → 40 → 30 → 20 → 10
    /// After pop()
    /// Top → 30 → 20 → 10
    T pop();

    /// @brief get the next value in in the stack without removing it
    /// @return the next value in the stack
    /// @example Top → 40 → 30 → 20
    /// peek() returns 40
    T peek() const;

    /// @brief check if the stack is empty
    /// @return true if empty
    bool isEmpty() const;

    // removed in favor of << operator
    // void display();
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Stack<U> &stack);
};

#include "stack.tpp"

#endif