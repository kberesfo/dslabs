template <typename T>
Stack<T>::Stack()
{
    top = nullptr;
    size = 0;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    if (top == nullptr)
    {
        return true;
    }

    return false;
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

    Node<T> *temp = top;
    top = top->next;
    T val = temp->data;

    delete temp;
    size -= 1;
    return val;
}

template <typename T>
void Stack<T>::push(T value)
{
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
