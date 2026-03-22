#include <iostream>

#include "linked_list/linked_list.h"

using namespace std;

int main()
{

    Stack<int> s;

    try
    {
        s.pop();
        cout << "Top element: " << s.peek() << "\n\n";
    }
    catch (const std::invalid_argument &e)
    {
        cout << "Error: " << e.what() << "\n\n";
    }

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << s << "\n";
    try
    {
        s.pop();
        cout << "Top element: " << s.peek() << "\n\n";
    }
    catch (const std::invalid_argument &e)
    {
        cout << "Error: " << e.what() << "\n";
    }

    cout << s << "\n"
         << endl;

    return 0;
}
