#include <stack>    // std::stack
#include <iostream> // std::cout
/*
Other stack functions:

stack::emplace() Adds a new element at the top of the stack, above its current top element. This 
element is constructed in place passing args as the arguments for its constructors.
This member function effectively calls the member function emplace_back of underlying 
container, forwarding args.

*/
namespace std;

int eval(const string &s)
{
    stack<int> eval_stack;
    stringstream ss(s);
    string symbol;

    while(getline(ss, symbol, ','))
    {
        if(symbol == "+" || symbol == "-" || symbol == "*" || symbol == "/")
        {
            int y = eval_stack.top();
            eval_stack.pop();

            int x = eval_stack.top();
            eval_stack.pop();
            switch(symbol.front())
            {
                case '+':
                    eval_stack.emplace(x+y);
                    break;
                case '-':
                    eval_stack.emplace(x-y);
                    break;
                case '*':
                    eval_stack.emplace(x*y);
                    break;
                case '/':
                    eval_stack.emplace(x/y);
                    break;
            }
        }else
        {
            eval_stack.emplace(stoi(symbol));
        }
    }
    return eval_stack.top();
}