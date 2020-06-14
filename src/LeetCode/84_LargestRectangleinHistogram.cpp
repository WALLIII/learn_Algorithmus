#include <iostream>
#include <vector>
#include <stack>
// 暴力法
// int largestRectangleArea(std::vector<int> &heights)
// {
//     int res = 0;
//     for (int i = 0; i < heights.size(); ++i)
//     {
//         int minH = heights[i];
//         for (int j = i; j < heights.size(); ++j)
//         {
//             minH = heights[j] >= minH ? minH : heights[j];
//             res = std::max(res, minH * (j - i + 1));
//         }
//     }
//     return res;
// }

// 分治法
// int helper(std::vector<int> &heights, int start, int end)
// {
//     if (start > end)
//         return 0;
//     int mid = start;
//     for (int i = start; i < end; ++i)
//     {
//         if (heights[i] < heights[mid])
//             mid = i;
//     }
//     return std::max(heights[mid] * (end - start + 1), std::max(helper(heights, start, mid - 1), helper(heights, mid + 1, end)));
// }
// int largestRectangleArea(std::vector<int> &heights)
// {
//     int size = heights.size();
//     return helper(heights, 0, size - 1);
// }
// 单调栈
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

int main()
{
    std::vector<int> numbers = {2,1,5,6,2,3};
    std::cout << largestRectangleArea(numbers) << std::endl;
}