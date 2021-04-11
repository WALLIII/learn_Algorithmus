#include <vector>
#include <iostream>

// 和为s的连续正数序列
std::vector<std::vector<int>> FindContinuousSequence(int sum)
{
    std::vector<std::vector<int>> results;
    std::vector<int> serie;
    if (sum < 3)
        return results;
    int small = 1, big = 2;
    int middle = (1 + sum) / 2;
    int curSum = small + big;
    while (small < middle)
    {
        if (curSum == sum)
        {
            for (int i = small; i <= big; ++i)
                serie.push_back(i);
            results.push_back(serie);
            serie.clear();
        }
        while (curSum > sum && small < middle)
        {
            curSum -= small;
            small++;
            if (curSum == sum)
            {
                for (int i = small; i <= big; ++i)
                    serie.push_back(i);
                results.push_back(serie);
                serie.clear();
            }
        }
        big++;
        curSum += big;
    }
    return results;
}

int main()
{

    std::vector<std::vector<int>> result;
    result = FindContinuousSequence(15);
    if (result.size() > 0)
    {
        for (auto row : result)
        {
            for (auto a : row)
            {
                std::cout << a << "  ";
            }
            std::cout << std::endl;
        }
    }
    else
        std::cout << "not finded" << std::endl;
    return 0;
}