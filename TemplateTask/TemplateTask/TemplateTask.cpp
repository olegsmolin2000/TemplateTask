#include"Stack.h"
#include <iostream>

using namespace std;

int main()
{
    Stack<int> a(2);

    a.push(0);
    a.push(5);

    a.pop();

    
    a.push(1);


    Stack<int> b(3);

    b.push(6);
    b.push(61);
    b.push(26);

  

    b.pop();

    b.push(10);
    cout << a.pop() << endl;
    a.printStack();
    b.printStack();
    
    Stack<int> c = StackUnion(a, b);
    c.printStack();

    return 0;
}
