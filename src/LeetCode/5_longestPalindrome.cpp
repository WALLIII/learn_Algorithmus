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
    int length=s.size();
    std::vector<std::vector<int>> dp(length, std::vector<int>(length,0));
    if(length<=1)
        return s;
    for(int i=0;i<length;++i){
        dp[i][i]=1;
    }
    int maxLength=1;
    int start=0;
    for(int i=1;i<length;++i){
        for(int j=0;j<i;++j){
            if(s[i]==s[j]){
                if(i-j<=2){
                    dp[j][i]=1;
                }
                else{
                    dp[j][i]=dp[j+1][i-1];
                }
            }
            if(dp[j][i]){
                if((i-j+1)>maxLength){
                    start=j;
                    maxLength=i-j+1;
                }
            }
        }
    }
    return s.substr(start, maxLength);
}
int main()
{
    std::string s = "";
    std::cout << longestPalindrome(s) << std::endl;
}