#include <vector>
#include <iostream>

std::vector<std::vector<int>> generateMatrix(int n)
{
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    if (n <= 0)
        return matrix;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int count = 1;
    while (top <= bottom && left <= right)
    {
        // top : left to right
        for (int i = left; i <= right; ++i)
        {
            matrix[top][i] = count;
            ++count;
        }
        if (++top > bottom)
            break;
        // top to bottom : right
        for (int i = top; i <= bottom; ++i)
        {
            matrix[i][right] = count;
            ++count;
        }
        if (--right < left)
            break;
        // bottom : right to left
        for (int i = right; i >= left; --i)
        {
            matrix[bottom][i] = count;
            ++count;
        }
        if (--bottom < top)
            break;
        // bottom to top : left
        for (int i = bottom; i >= top; --i)
        {
            matrix[i][left] = count;
            ++count;
        }
        if (++left > right)
            break;
    }
    return matrix;
}

int main()
{
    std::vector<std::vector<int>> matrix;
    matrix = generateMatrix(4);
    std::cout << std::endl;
    for (auto row : matrix)
    {
        for (auto a : row)
        {
            std::cout << a << "  ";
        }
        std::cout << std::endl;
    }
    return 0;
}