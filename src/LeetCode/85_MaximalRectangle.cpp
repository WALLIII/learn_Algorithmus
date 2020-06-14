#include <stack>
#include <iostream>
#include <vector>

int largestRectangleArea(std::vector<int> &heights)
{
    std::stack<int> sk;
    heights.push_back(0);
    int res = 0;
    for (int i = 0; i < heights.size(); ++i)
    {
        while (!sk.empty() && (heights[sk.top()] >= heights[i]))
        {
            int val = sk.top();
            sk.pop();
            int tmparea = heights[val] * (sk.empty() ? i : (i - sk.top() - 1));
            res = std::max(res, tmparea);
        }
        sk.push(i);
    }
    return res;
}

int maximalRectangle(std::vector<std::vector<char>> &matrix)
{
    if (matrix.size() == 0)
        return 0;
    int size = matrix[0].size();
    std::vector<int> dp(size, 0);
    int maxA=0;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
        }
        
        maxA = std::max(maxA, largestRectangleArea(dp));
    }
    return maxA;
}

int main()
{
    char a[4][5] = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    std::vector<std::vector<char>> matrix(4, std::vector<char>(5, '0'));
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            matrix[i][j] = a[i][j];
        }
    }
    for (auto row : matrix)
    {
        for (auto c : row)
        {
            std::cout << c << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << maximalRectangle(matrix) << std::endl;
    return 0;
}