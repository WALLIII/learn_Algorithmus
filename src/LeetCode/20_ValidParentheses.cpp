#include <string>
#include <unordered_map>
#include <iostream>
#include<stack>

bool isValid(std::string s)
{
    if(s.size()==0)
        return true;
    if(s.size()==1)
        return false;
    std::stack<int> sk;
    bool isValid=false;
    std::unordered_map<char, int> map{{'(',1},{'[',2},{'{',3}, \
                                        {')',-1},{']',-2},{'}',-3}};
    int i=0;
    while(i<s.size()){
        while(map[s[i]]>=1&&map[s[i]]<=3){
            // std::cout<<"push: "<<s[i]<<std::endl;
            sk.push(map[s[i]]);
            ++i;
        }
        if(i>s.size()-1)
            return false;
        while(map[s[i]]>=-3&&map[s[i]]<=-1){
            if(sk.empty())
                return false;
            int tmp=sk.top();
            // std::cout<<"tmp:  "<<tmp<<std::endl;
            if(tmp+map[s[i]]==0){
                // std::cout<<"tmp+map==0----->"<<std::endl;
                isValid=true;
            }
            else 
                return false;
            sk.pop();
            ++i;
        }
    }
    if(sk.empty())
        return isValid;
    else
    {
        return false;
    }
    
}

int main()
{
    std::string s="([]";
    std::cout<<isValid(s)<<std::endl;
} Valid Parentheses