#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>> &grid, int r, int c)
{
    int nc = grid[0].size(), nr = grid.size();

    if (r == -1 || r == nr || c == -1 || c == nc || grid[r][c] == '0')
        return;
    grid[r][c] = '0';
    dfs(grid, r - 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r + 1, c);
    dfs(grid, r, c + 1);
    return;
}

int numIslands(vector<vector<char>> &grid)
{
    if (grid.empty() || grid.size() == 0 || grid[0].size() == 0)
        return 0;
    int nc = grid[0].size(), nr = grid.size();

    int num = 0;
    for (int i = 0; i < nr; ++i)
    {
        for (int j = 0; j < nc; ++j)
        {
            if (grid[i][j] == '1')
            {
                num++;
                dfs(grid, i, j);
            }
        }
    }
    return num;
}
int main()
{
    vector<vector<char>> grid(4, vector<char>(5, '0'));
    char g[4][5] = {{'1', '1', '0', '0', '0'},
                    {'1', '1', '0', '0', '0'},
                    {'0', '0', '1', '0', '0'},
                    {'0', '0', '0', '1', '1'}};
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            grid[i][j] = g[i][j];
        }
    }
    cout << numIslands(grid) << endl;
}