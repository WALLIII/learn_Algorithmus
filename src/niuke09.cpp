#include <stack>
#include <iostream>

void push(int node, std::stack<int> stack1, std::stack<int> stack2)
{
    stack1.push(node);
}

int pop(std::stack<int> stack1, std::stack<int> stack2)
{
    if (stack2.empty())
    {
        while (!stack1.empty())
        {
            int &tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
    }
    int head = stack2.top();
    stack2.pop();
    return head;
}