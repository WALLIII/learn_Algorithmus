#include <iostream>
#include <vector>

int climbStairs(int n)
{
    std::vector<int> dp(n,0);
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<n;++i){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n-1];
}

int main()
{
    std::cout << climbStairs(6) << std::endl;
    return 0;
}