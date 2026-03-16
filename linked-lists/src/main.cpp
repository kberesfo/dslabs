#include <iostream>

#include "linked_list/linked_list.h"

using namespace std;

int main()
{

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << s << "\n";

    s.pop();

    cout << "Top element: " << s.peek() << endl;

    cout << s << "\n"
         << endl;

    return 0;
}
