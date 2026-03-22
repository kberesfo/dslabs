template <typename T>
Stack<T>::Stack()
{
    top = nullptr;
    size = 0;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return top == nullptr;
}

template <typename T>
T Stack<T>::peek() const
{
    if (isEmpty())
    {
        throw std::invalid_argument("Stack Underflow");
    }

    return top->data;
}

template <typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        throw std::invalid_argument("Stack Underflow");
    }
    // create a temp node pointer
    Node<T> *temp = top;
    // set top to the next element in the list
    top = top->next;
    // get the value from temp
    T val = temp->data;
    // free up the memory
    delete temp;
    size -= 1;
    // return the value
    return val;
}

template <typename T>
void Stack<T>::push(T value)
{
    // create a new value and store it at the top of the stack
    Node<T> *temp = new Node<T>{value, nullptr};
    temp->next = top;
    top = temp;
    size += 1;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Stack<T> &stack)
{
    Node<T> *currentNode = stack.top;
    // print size
    os << "Current Size: " << stack.size << "\n";
    os << "Current Stack: \n";

    while (currentNode != nullptr)
    {
        os << "[ " << currentNode->data << " | " << currentNode->next << " ]\n";
        currentNode = currentNode->next;
    }

    return os;
}
