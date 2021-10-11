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


double do_operation(char op, double a, double b)
{
    double result;

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

double solution(const std::string &str)
{
    ListStack<double> nums;
    ListStack<char> op;
    std::string num;
    int i = 0;
    double a, b;

    while(str[i] != '\0')
    {
        if(isdigit(str[i]))
        {

            while(isdigit(str[i]))
            {
                num.push_back(str[i]);
                i++; 
            }
        
            nums.push(std::stod(num));
            num.clear();
        }

        else if (str[i] == '-' && !isdigit(str[i - 1]) && str[i - 1] != ')') 
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
    
    // std::string exp1 = "16/2+5-11*2"; // -9
    // std::string exp2 = "3+4*2";       // 11
    // std::string exp3 = "2*5+8*2";     // 26
    // std::string exp4 = "-3+4";        // 1
    // std::string exp5 = "-3+-4";      // -7 
    // std::string exp6 = "2+-3";          // -1
    // std::string exp7 = "3*(4-2*(3+7))+6"; // -42
    // std::string exp8 = "8+4*(10-5/(5+10))-3*7"; // 25.6667
    std::string exp9 = "(3*(4-2*(3+7))+6/(5+6)-3*4)+1"; // -58.454545
    // std::string space = "2 + - \n3\n";
    // double a, b;
    // a = 5;
    // b = 15;

    // string.erase(std::remove_if(string.begin(), string.end(), ::isstring), string.end());

    std::cout << solution(exp9) << std::endl;


    // std::string input;
    // char cont_choice;
    // std::cout << "========CALCULATOR========\n\n";

    // while(cont_choice != 'q')
    // {
    //     std::cout << "Inputs allowed: 0-9,+,-,*,/. Paranthesis and negative numbers are allowed.\n";
    //     std::cout << "Enter an expression to be evaluated: ";
    //     getline(std::cin, input);
    //     input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());



    // }

    
}