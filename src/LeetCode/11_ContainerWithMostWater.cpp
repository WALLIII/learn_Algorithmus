#include <iostream>
#include <vector>

int maxArea(std::vector<int> &height)
{
    if (height.size() < 2)
        return 0;
    int MaxArea = 0, p1 = 0, p2 = height.size() - 1;
    while (p1 < p2)
    {
        int currArea = (p2 - p1) * std::min(height[p1], height[p2]);
        if (currArea > MaxArea)
        {
            MaxArea = currArea;
        }
        if (height[p1] >= height[p2])
            --p2;
        else
            ++p1;
    }
    return MaxArea;
}

int main()
{
    std::vector<int> heights{1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << "maximal area:  " << maxArea(heights) << std::endl;
    return 0;
}