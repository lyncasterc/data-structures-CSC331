#include <iostream>
#include "Stack.h"
#include "ListStack.h"

int main()
{
    Stack <int> s, s2;
    bool result;
    ListStack <int> ls, ls_2;

    ls.push(1);
    ls.push(3);
    ls.push(9);
   
    ls.pop();

    ls_2 = ls;

    result = ls.isEmpty();

    std::cout << ls_2.Top();


}