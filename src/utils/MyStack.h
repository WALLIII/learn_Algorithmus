#ifndef _MY_STACK_H
#define _MY_STACK_H
#include <stack>
#include <iostream>

class MyStack
{
public:
    void push(int value);
    void pop();
    int top();
    int min();

private:
    std::stack<int> stack1;
    std::stack<int> stack2;
};

void MyStack::push(int value)
{
    stack1.push(value);
    if (stack2.empty() || value <= stack2.top())
    {
        stack2.push(value);
    }
    else
    {
        stack2.push(stack2.top());
    }
}

void MyStack::pop()
{
    stack1.pop();
    stack2.pop();
}

int MyStack::top()
{
    return stack1.top();
}

int MyStack::min()
{
    return stack2.top();
}

#endif