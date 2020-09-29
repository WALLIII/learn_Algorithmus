#include <string>
#include <iostream>
#include<vector>
// std::string longestPalindrome(std::string s)
// {
//     std::string ans = "";
//     std::string temp = "";
//     for (int i = 0; i < s.size(); ++i)
//     {
//         for (int j = i; j < s.size(); ++j)
//         {
//             temp += s[j];
//             std::string revTemp = temp;
//             std::reverse(revTemp.begin(), revTemp.end());
//             if (temp == revTemp)
//             {
//                 ans = ans.size() > temp.size() ? ans : temp;
//             }
//         }
//         temp = "";
//     }
//     return ans;
// }
std::string longestPalindrome(std::string s)
{
       if (s.size() <= 1)
        return s;
    int len = s.size();
    vector<vector<bool>> dp(len, vector<bool>(len));
    for (int i = 0; i < len; ++i)
    {
        dp[i][i] = true;
    }
    int maxLen=1, start=0;
    for(int j=1;j<len;++j){
        for(int i=0;i<j;++i){
            // 先判断s[i...j]的头尾是否相等，如果不想等就直接为false了
            if(s[i]!=s[j])
                dp[i][j]=false;
            // 在头尾相等的情况下判断子问题是否为true
            else{
                if(j-i<3){
                    dp[i][j]=true;
                }
                // 如果s[i...j]的长度大于3就：
                else{
                    dp[i][j]=dp[i+1][j-1];
                }
            }
            // 如果s[i...j]是回文串的话判断当前的长度是否为当前的最佳值
            if(dp[i][j] && (j-i+1)>maxLen){
                maxLen=j-i+1;
                start=i;
            }
        }
    }
    return s.substr(start, maxLen);
}
int main()
{
    std::string s = "";
    std::cout << longestPalindrome(s) << std::endl;
}