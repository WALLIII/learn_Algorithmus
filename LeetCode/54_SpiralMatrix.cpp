#include <vector>
#include <iostream>

std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
{
    std::vector<int> ans;
    if(matrix.empty())
        return ans;
    int row = matrix.size() - 1;
    int col = matrix[0].size() - 1;
    int top = 0, bottom = row, left = 0, right = col;
    while (top <= bottom && left <= right)
    {
        // top : left to right
        for (int i = left; i <= right; ++i)
        {
            ans.push_back(matrix[top][i]);
        }
        if (++top > bottom)
            break;
        // top to bottom : right
        for (int i = top; i <= bottom; ++i)
        {
            ans.push_back(matrix[i][right]);
        }
        if (--right < left)
            break;
        // bottom : right to left
        for (int i = right; i >= left; --i)
        {
            ans.push_back(matrix[bottom][i]);
        }
        if (--bottom < top)
            break;
        // bottom to top : left
        for (int i = bottom; i >= top; --i)
        {
            ans.push_back(matrix[i][left]);
        }
        if (++left > right)
            break;
    }
    return ans;
}

int main()
{
    std::vector<std::vector<int>> matrix(3, std::vector<int>(1, 0));
    int arr[3][1] = {{1},{2},{3}};
    // std::cout<<matrix.size()<<"  "<<matrix[0].size()<<std::endl;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            matrix[i][j] = arr[i][j];
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::vector<int> ans = spiralOrder(matrix);
    std::cout << std::endl;
    for (auto a : ans)
        std::cout << a << "  ";
    std::cout << std::endl;
    return 0;
}