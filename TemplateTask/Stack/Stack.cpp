#include <iostream>
#include "Stack.h"

int main()
{
    Stack<int> a(2);

    a.push(1);
    a.push(1);

    Stack<int> b(3);

    b.push(2);

    Stack<int> c = StackUnion(a, b);

    c.printStack();


    return 0;

}