#include <string>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(std::string s)
{
    if (s.size() <=0)
        return true;
    unordered_map<char, char> hash = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    stack<char> sk;
    sk.push('?');
    int i = 0;
    while (i < s.size())
    {
        if(hash.find(s[i])!=hash.end()){
            sk.push(s[i]);
        }
        //如果不是左括号的话
        else if(hash.find(s[i])==hash.end()){
            if(s[i]==hash[sk.top()]){
                sk.pop();
            }
            else{
                return false;
            }
        }
        ++i;
    }
    if(sk.size()>1)  return false;
    else    return true;
}


int main()
{
    std::string s1 = "([]";
    std::string s2 = "()[]{}";
    std::string s3 = "((([])))";
    std::string s4 = "(([))]";
    std::cout << "s1:  " << s1 << "  " <<isValid(s1) << std::endl;
    std::cout << "s2:  " << s2 << "  " <<isValid(s2) << std::endl;
    std::cout << "s3:  " << s3 << "  " <<isValid(s3) << std::endl;
    std::cout << "s4:  " << s4 << "  " <<isValid(s4) << std::endl;
}