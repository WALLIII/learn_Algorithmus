#include <iostream>
#include <vector>
using namespace std;
static int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, int row, int col)
{
    int rows = matrix.size(), cols = matrix[0].size();
    //如果当前节点被访问过了，即memo！=0，就返回当前节点保存下来的值，即到目前节点的最长递增路径
    if (memo[row][col] != 0)
        return memo[row][col];
    memo[row][col]++;
    for (int i = 0; i < 4; ++i)
    {
        int newrow = row + dirs[i][0], newcol = col + dirs[i][1];
        if (newrow >= 0 && newrow < rows && newcol >= 0 && newcol < cols && matrix[row][col] < matrix[newrow][newcol])
        {
            memo[row][col] = max(memo[row][col], 1 + dfs(matrix, memo, newrow, newcol));
        }
    }
    return memo[row][col];
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    if (rows == 0 || cols == 0)
        return 0;
    vector<vector<int>> memo(rows, vector<int>(cols, 0));
    int res = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            res = max(res, dfs(matrix, memo, i, j));
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    int res = longestIncreasingPath(matrix);
    cout << res << endl;
}