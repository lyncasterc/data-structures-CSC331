#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include "ListStack.h"

// returns the precedence of operators in the expression
int str_prec(char x)
{
    if(x == '+' || x == '-')
    { return 1; }

    else if(x == '*' || x == '/')
    { return 3; }

    else if(x == '(')
    { return 8; }

    else if(x == ')')
    { return 0; }

    return -1;  
};


// returns the precendence of operators once inside the operator stack
int stack_prec(char x)
{
    if(x == '+' || x == '-')
    { return 2; }

    else if(x == '*' || x == '/')
    { return 4; }

    else if(x == '(')
    { return 0; }

    return -1; 
};


int do_operation(char op, int a, int b)
{
    int result;

    switch (op)
    {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
    }

    return result;
}

int solution(const std::string &str)
{
    ListStack<int> nums;
    ListStack<char> op;
    std::string num;
    int i = 0, a, b;

    while(str[i] != '\0')
    {
        if(isdigit(str[i]))
        {

            while(isdigit(str[i]))
            {
                num.push_back(str[i]);
                i++; 
            }
        
            nums.push(std::stoi(num));
            num.clear();
        }

        else if (str[i] == '-' && !isdigit(str[i - 1])) 
        {
            num.push_back(str[i++]);
        }

        else if (op.isEmpty() || str_prec(str[i]) > stack_prec(op.Top()))
        {
            op.push(str[i++]);
        }

        else if (str_prec(str[i]) < stack_prec(op.Top()))
        {
            b = nums.pop();
            a = nums.pop();
            nums.push(do_operation(op.pop(), a, b));
        }
        
        else
        {
            op.pop();
        }
    }

    while(!op.isEmpty() && op.Top() != ')')
    {
        b = nums.pop();
        a = nums.pop();
        nums.push(do_operation(op.pop(), a, b));
    }

    return nums.pop();
};


int main()
{
    
    std::string exp1 = "16/2+5-11*2"; // -9
    std::string exp2 = "3+4*2";       // 11
    std::string exp3 = "2*5+8*2";     // 26
    std::string exp4 = "-3+4";        // 1
    std::string exp5 = "-3+-4";      // -7 
    std::string exp6 = "2+-3";          // -1
    std::string exp7 = "3*(4-2*(3+7))+6"; // -42
    std::string exp8 = "8+4*(10-5/(5+10))-3*7"; // ??
    std::string space = "2 + - \n3\n";
    space.erase(std::remove_if(space.begin(), space.end(), ::isspace), space.end());

    std::cout << solution(exp7) << std::endl;
    
}