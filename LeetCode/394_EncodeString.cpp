#include <string>
#include <iostream>
#include <stack>
std::string decodeString(std::string s)
{
    std::stack<std::string> strs;
    std::stack<int> nums;
    int num = 0;
    std::string res = "";
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num = num * 10 + s[i] - '0';
        }
        else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]=='['){
            nums.push(num);
            num=0;
            strs.push(res);
            res="";
        }
        else{
            int times=nums.top();
            nums.pop();
            for(int j=0;j<times;++j){
                strs.top() += res;
                std::cout<<strs.top()<<std::endl;
            }
            // std::cout<<"res:  "<<res<<std::endl;
            res=strs.top();
            // std::cout<<"res=strs.top():  "<<res<<std::endl;
            strs.pop();
        }
    }
    return res;
}

int main()
{
    std::string str = "3[a]2[b4[F]c]";
    std::string ans = decodeString(str);
    std::cout << ans << std::endl;

    return 0;
}