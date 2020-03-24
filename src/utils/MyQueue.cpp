#include "MyQueue.h"
#include <stack>


void MyQueue::push(int node)
{
    stack1.push(node);
}

int MyQueue::pop()
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
