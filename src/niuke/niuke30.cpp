#include<iostream>
#include<stack>


class MyStack
{
public:
    void push(int value);
    void pop();
    int top();
    int min();

private:
    std::stack<int> sk;
    std::stack<int> ass;
};

void MyStack::push(int value){
    sk.push(value);
    if(ass.empty()||value<=ass.top()){
        ass.push(value);
    }
    else{
        ass.push(ass.top());
    }
}

void MyStack::pop(){
    sk.pop();
    ass.pop();
}

int MyStack::min(){
    return ass.top();
}

int MyStack::top(){
    return sk.top();
}
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