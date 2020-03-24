#include "utils/MyStack.h"
#include <stack>
#include <iostream>

int main()
{
    MyStack stack1;
    stack1.push(3);
    stack1.push(4);
    stack1.push(2);
    stack1.push(1);
    std::cout << "minimal value: " << stack1.min() << std::endl;
    stack1.pop();
    stack1.pop();
    stack1.push(0);
    std::cout << "minimal value: " << stack1.min() << std::endl;
    return 0;
}