#include <vector>
#include <string>
#include <iostream>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1)
        return 0;
    vector<vector<int>> dp(rows, vector<int>(cols));
    dp[0][0] = 1;
    for (int i = 1; i < rows; ++i)
    {
        dp[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 0) ? 1 : 0;
    }
    for (int j = 1; j < cols; ++j)
    {
        dp[0][j] = (obstacleGrid[0][j] == 0 && obstacleGrid[0][j - 1] == 0) ? 1 : 0;
    }
    for (int i = 1; i < rows; ++i)
    {
        for (int j = 1; j < cols; ++j)
        {
            if (obstacleGrid[i][j] == 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            else if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
        }
    }
    return dp[rows - 1][cols - 1];
}

int main()
{
    vector<vector<int>> obstacleGrid = {{0,1,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0}};
    int res=uniquePathsWithObstacles(obstacleGrid);
    cout<<res<<endl;
    return 0;
}
