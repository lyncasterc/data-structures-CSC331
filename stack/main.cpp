#include <iostream>
#include "Stack.h"
// #include "ListStack.h"

int main()
{
    Stack <int> s, s2;
    bool result;
    // ListStack <int> ls;

    s.push(1);
    s.push(3);
    s.push(0);
    s.pop();
    s.pop();

    s2 = s;

    result = s2.isEmpty();

    std::cout << s2.Top();


}