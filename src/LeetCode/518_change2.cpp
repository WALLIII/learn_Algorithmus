#include <vector>
#include <string>
#include <iostream>

using namespace std;

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= amount; ++j)
        {
            if (j >= coins[i - 1])
            {

                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for (auto row : dp)
    {
        for (auto a : row)
            cout << a << "  ";
        cout << endl;
    }
    return dp[n][amount];
}
int change2(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= amount; ++j)
        {
            if (j >= coins[i - 1])
            {
                dp[j] = dp[j] + dp[j - coins[i - 1]];
            }
        }
    }
    return dp[amount];
}
int main()
{
    vector<int> coins = {1, 2, 5};
    int res = change2(5, coins);
    cout << res << endl;
    return 0;
}
