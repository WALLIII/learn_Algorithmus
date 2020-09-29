#include <vector>
#include <string>
#include <iostream>

using namespace std;

int minDistance(string word1, string word2) {
        int len1=word1.size(), len2=word2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1,0));
        //初始化第一列、第一行
        for(int i=1;i<=len1;++i) dp[i][0]=i;
        for(int j=1;j<=len2;++j) dp[0][j]=j;
        for(int i=1;i<=len1;++i){
            for(int j=1;j<=len2;++j){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(dp[i-1][j-1], min(dp[i][j-1],dp[i-1][j]))+1;
                }
            }
        }
        for(auto row:dp){
            for(auto a:row)
                cout<<a<<"  ";
            cout<<endl;
        }
        return dp[len1][len2];
    }
int main()
{
    
    int res=minDistance("horse", "ros");
    cout<<res<<endl;
    return 0;
}
