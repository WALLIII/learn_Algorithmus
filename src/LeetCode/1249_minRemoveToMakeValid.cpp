#include <string>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
string minRemoveToMakeValid(string s)
{
    if (s.empty())
        return "";
    unordered_map<char, char> hash = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    stack<int> sk;
    sk.push(-1);
    for (int i = 0; i < s.size(); ++i)
    {
        if (isalpha(s[i]))
        {
            continue;
        }
        //是左括号
        else if (hash.find(s[i]) != hash.end())
        {
            sk.push(i);
        }
        //是右括号
        else if (hash.find(s[i]) == hash.end())
        {
            //若和栈顶匹配上了，合法；
            if(hash[s[sk.top()]]==s[i]&&(sk.size()>1))
            {
                sk.pop();
            }
            //不合法的标上*
            else
            {
                s[i] = '*';
            }
        }
    }
    while (sk.size()>1)
    {
        s[sk.top()] = '*';
        sk.pop();
    }
    s.erase(remove(s.begin(), s.end(), '*'), s.end());
    return s;
}
int main()
{
    string s1 = "lee(t(c)o)de)";
    string s2 = "a)b(c)d";
    cout << minRemoveToMakeValid(s1) << endl;
    cout<<minRemoveToMakeValid(s2)<<endl;
    return 0;
}