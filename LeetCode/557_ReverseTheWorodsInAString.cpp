#include <string>
#include <iostream>
#include<stack>

// std::string reverseWords(std::string s)
// {
//     std::string tmp="", ans="";
//     for(auto c:s){
//         if(c==' '){
//             reverse(tmp.begin(), tmp.end());
//             ans+=tmp;
//             tmp="";
//             ans+=' ';
//         }
//         else
//             tmp+=c;
//     }
//     if(tmp!=""){
//         reverse(tmp.begin(), tmp.end());
//         ans+=tmp;
//     }
//     return ans;
// }
std::string reverseWords(std::string s)
{
    std::stack<char> sk;
    std::string ans="";
    for(auto c:s){
        if(c==' '){
            while(!sk.empty()){
                ans += sk.top();
                sk.pop();
            }
            ans+=' ';  
        }
        else
            sk.push(c);
    }
    while(!sk.empty()){
        ans+=sk.top();
        sk.pop();
        
    }
    return ans;
     
}
int main()
{
    std::string s = "wie kann es moglich sein";

    std::string ans = reverseWords(s);
    std::cout << ans << "sign"<<std::endl;
    return 0;
}