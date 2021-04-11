#include <vector>
#include <iostream>
#include <unordered_map>
// 不排序的方法
// bool isStraight(std::vector<int> &nums)
// {
//     if (nums.size() < 5)
//         return false;
//     std::unordered_map<int, int> hash(0);
//     int min = INT_MAX, max = INT_MIN;
//     for (int i = 0; i < nums.size(); ++i)
//     {
//         if (nums[i] == 0)
//         {
//             continue;
//         }
//         hash[nums[i]]++;
//         if (hash[nums[i]] > 1)
//         {
//             return false;
//         }
//         if (nums[i] > max)
//             max = nums[i];
//         if (nums[i] < min)
//             min = nums[i];
//     }
//     if ((max - min) < 5)
//         return true;

//     return false;
// }
bool isStraight(std::vector<int> numbers)
{
    if (numbers.size() != 5)
        return false;
    int zeros = 0, gaps = 0;
    int i = 0;
    std::sort(numbers.begin(), numbers.end());
    for (auto a : numbers)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    while (i < 5 && numbers[i] == 0)
    {
        zeros++;
        i++;
    }
    std::cout << "zeros:  " << zeros << std::endl;
    i = zeros;
    while (i < 4)
    {
        if (numbers[i + 1] == numbers[i])
        {
            return false;
        }

        gaps += numbers[i + 1] - numbers[i] - 1;

        i++;
    }
    std::cout << "gaps:  " << gaps << std::endl;
    if (zeros >= gaps)
        return true;
    else
        return false;
}
int main()
{
    std::vector<int> numbers = {1, 1, 0, 0, 0};
    if (isStraight(numbers))
        std::cout << "IsContinuous!!!" << std::endl;
    else
        std::cout << "not Continuous!!!" << std::endl;
    return 0;
}