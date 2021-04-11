#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int row = grid.size(), col = grid[0].size();
    if (row == 0 || col == 0)
        return 0;
    vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else if (i > 0 && j == 0)
            {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            }
            else if (i == 0 && j > 0)
            {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
    }
    return dp[row - 1][col - 1];
}

int main()
{
    vector<vector<int>> grid(3, vector<int>(3, 0));
    int arr[3][3] = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            grid[i][j] = arr[i][j];
        }
    }
    // for (auto a : grid)
    //     for (auto b : a)
    //         cout << b << "   ";
    std::cout << minPathSum(grid) << std::endl;
}