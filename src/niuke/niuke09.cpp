#include <stack>
#include<iostream>
class myQueue
{
private:
    std::stack<int> stack1;
    std::stack<int> stack2;

public:
    int pop()
    {
       int tmp=0;
       if (!stack2.empty())
        {
            tmp = stack2.top();
            stack2.pop();
            return tmp;
        }
        else
        {
            while (!stack1.empty())
            {
                int s1=stack1.top();
                stack2.push(s1);
                stack1.pop();
            }
            tmp = stack2.top();
            stack2.pop();
            return tmp;
        }
    }
    void push(int node)
    {
        stack1.push(node);
    }
};

int main()
{
    myQueue que;
    que.push(1);
    que.push(2);
    que.push(3);
    std::cout<<que.pop()<<std::endl;
    std::cout<<que.pop()<<std::endl;
    std::cout<<que.pop()<<std::endl;
    return 0;
}