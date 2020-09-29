#include <iostream>
#include <stack>

using namespace std;
//简单版计算机，只能算加减法，不带括号
int calculate(string s)
{
    int num = 0;
    stack<int> sk;
    char sign = '+';
    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        if (isdigit(c))
        {
            num = num * 10 + (c - '0');
        }
        if (!isdigit(c) || i == s.size() - 1)
        {
            switch (sign)
            {
            case '+':
                sk.push(num);
                break;
            case '-':
                sk.push(-num);
                break;
            }
            sign = c;
            num = 0;
        }
    }
    int res = 0;
    while (!sk.empty())
    {
        cout<<sk.top()<<"  ";
        res += sk.top();
        sk.pop();
    }
    cout<<endl;
    return res;
}
//在calculate基础上加上*、/、处理空格的功能
int calculate2(string s)
{
    int num = 0;
    stack<int> sk;
    char sign = '+';
    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        if (isdigit(c))
        {
            num = num * 10 + (c - '0');
        }
        if ((!isdigit(c) && c!=' ')|| i == s.size() - 1)
        {
            switch (sign)
            {
            int pre;
            case '+':
                sk.push(num);
                break;
            case '-':
                sk.push(-num);
                break;
            case '*':
                pre=sk.top();
                sk.pop();
                sk.push(pre*num);
                break;
            case '/':
                pre=sk.top();
                sk.pop();
                sk.push(pre/num);
                break;
            }
            sign = c;
            num = 0;
        }
    }
    int res = 0;
    while (!sk.empty())
    {
        res += sk.top();
        sk.pop();
    }
    return res;
}
////加上括号处理功能
int help(string s, int &i)
{
    int num = 0;
    stack<int> sk;
    char sign = '+';
    for (i; i < s.size(); ++i)
    {
        
        if (isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }
        if(s[i]=='('){
            num=help(s, ++i);
            i++;
        }
        if ((!isdigit(s[i]) && s[i]!=' ')|| i == s.size() - 1)
        {
            switch (sign)
            {
            int pre;
            case '+':
                sk.push(num);
                break;
            case '-':
                sk.push(-num);
                break;
            case '*':
                pre=sk.top();
                sk.pop();
                sk.push(pre*num);
                break;
            case '/':
                pre=sk.top();
                sk.pop();
                sk.push(pre/num);
                break;
            }
            sign = s[i];
            num = 0;
        }
        if(s[i]==')') break;
    }
    int res = 0;
    while (!sk.empty())
    {
        res += sk.top();
        sk.pop();
    }
    return res;
}

int calculate3(string s)
{
    int begin=0;
    return help(s, begin);
}
int main()
{
    string s = "(1+(4+5+2)-3)+(6+8)";
    int res = calculate3(s);
    cout << res << endl;
}