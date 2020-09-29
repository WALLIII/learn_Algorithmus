#include <vector>
#include <string>
#include <iostream>

bool isMatch(std::string s, std::string p)
{
    int ns = s.size(), np = p.size();
    // 如果sp同时为空，true.如果p为空但是s不为空，false.
    if (p.empty())
        return s.empty();
    // 建立动态规划的数组，之所以长度要+1是因为
    std::vector<std::vector<bool>> dp(ns + 1, std::vector<bool>(np + 1, false));
    dp[0][0] = true;
    // 先对s为空但p不为空的情况进行初始化。如果要能匹配上，p至少有两个字符，a*的形式可以消去a。
    for (int i = 1; i <= np; ++i)
    {
        if (i - 2 >= 0 && p[i - 1] == '*' && p[i - 2])
            dp[0][i] = dp[0][i - 2];
        // std::cout<<"i:"<<0<<"  j:"<<i<<"  dp[i][j]:"<<dp[0][i]<<std::endl;
    }
    // 如果s和p都不为空，会进行以下的循环，用dp的方法求出最后的答案
    for (int i = 1; i <= ns; ++i)
    {
        for (int j = 1; j <= np; ++j)
        {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1];
            if (p[j - 1] == '*')
            {
                bool zero, one;
                if (j - 2 >= 0)
                {
                    // a*的模式，消去a的情况：2.2的情况
                    zero = dp[i][j - 2];
                    //  a*的a重复1～无处次：2.1的情况
                    one = (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j];
                    dp[i][j] = zero || one;
                }
            }
            // std::cout<<"i:"<<i<<"  j:"<<j<<"  dp[i][j]:"<<dp[i][j]<<std::endl;
        }
    }
    // for(auto row:dp){
    //     for(auto a:row){
    //         std::cout<<a<<"  ";
    //     }
    //     std::cout<<std::endl;
    // }
    return dp[ns][np];
}

void test(std::string s, std::string p)
{
    if (isMatch(s, p))
    {
        std::cout << "s: " << s << " and p: " << p << " is matched.." << std::endl;
    }
    else
    {
        std::cout << "s: " << s << " and p: " << p << " is not matched.." << std::endl;
    }
}

int main()
{
    // test("mississippi", "mis*is*p*");
    // test("aa", "a");
    // test("aa", "a*");
    test("aab", "c*a*b");
    // test("", "a*");
}