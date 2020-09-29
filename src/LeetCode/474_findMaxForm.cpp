#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int dp[601][101][101];
int findMaxForm(vector<string> &strs_, int m, int n)
{
    int len = strs_.size();
    if (len <= 0)
        return 0;
    vector<string> strs;
    strs.push_back("-1");
    for (int i = 0; i < len; ++i)
    {
        strs.push_back(strs_[i]);
    }
    std::memset(dp, 0, sizeof dp);
    for (int i = 1; i <= len; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            for (int k = 0; k <= n; ++k)
            {
                //不考虑当前的字符串
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                //计算strs[i]中0和1的个数
                int one = 0, zero = 0;
                for (int x = 0; x < strs[i].size(); ++x)
                {
                    if (strs[i][x] == '0')
                        zero++;
                    else
                        one++;
                }
                if (j - zero >= 0 && k - one >= 0)
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j - zero][k - one]+1);
            }
        }
    }
    return dp[len][m][n];
}
int main()
{
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int res = findMaxForm(strs, 5, 3);
    cout << res << endl;
}