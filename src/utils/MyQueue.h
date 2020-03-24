#ifndef _MY_QUEUE
#define _MY_QUEUE
#include <stack>
#include <iostream>

class MyQueue
{
public:
    void push(int node);
    int pop();

private:
    std::stack<int> stack1;
    std::stack<int> stack2;
};


#endif //_MY_QUEUE