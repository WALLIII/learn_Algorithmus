#include <vector>
#include <iostream>

std::vector<int> FindNumbersWithSum(std::vector<int> array, int sum)
{
    std::vector<int> result;
    if (array.size() <= 1)
        return result;
    int p1 = 0, p2 = array.size() - 1;
    int product = INT_MAX;
    while (p1 < p2)
    {
        if ((array[p1] + array[p2]) == sum)
        {
            if ((array[p1] * array[p2]) < product)
            {
                product = array[p1] * array[p2];
                result.clear();
                result.push_back(array[p1]);
                result.push_back(array[p2]);
            }
            p1++;
            p2--;
        }
        else if ((array[p1] + array[p2]) < sum)
        {
            p1++;
        }
        else
        {
            p2--;
        }
    }
    return result;
}
// 第二个问题的答案：和为s的连续正数序列
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
        curSum+=big;
    }
    return results;
}



int main()
{
    std::vector<int> array = {1, 2, 4, 7, 8, 11, 15};
    std::vector<int> result;
    result = FindNumbersWithSum(array, 15);
    if (result.size() > 0)
    {
        for (auto a : result)
            std::cout << a << "  ";
        std::cout << std::endl;
    }
    else
        std::cout << "not finded" << std::endl;
    return 0;
}