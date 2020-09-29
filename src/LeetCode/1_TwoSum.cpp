#include <map>
#include <vector>
#include <iostream>
#include<unordered_map>

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::vector<int> res;
    if (nums.size() <= 1)
        return res;
    std::unordered_map<int, int> m;
    for(int i=0;i<nums.size();++i)
        m[nums[i]]=i;
    std::sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
        if ((nums[i] + nums[j]) == target)
        {
            std::cout<<"i:  "<<i<<"  j:  "<<j<<std::endl;
            res.push_back(m[nums[i]]);
            res.push_back(m[nums[j]]);
            return res;
        }
        else if ((nums[i] + nums[j]) < target)
            ++i;
        else
            --j;
    }
    return res;
}
std::vector<int> twoSum2(std::vector<int> &nums, int target)
{
      std::unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(nums[i]) != m.end())
            return {m[nums[i]], i};
        m[target-nums[i]] = i;
    }
    return {};
}
int main()
{
    std::vector<int> nums = {3,3};
    std::vector<int> res;
    res = twoSum(nums, 6);
    for (auto a : res)
        std::cout << a << "   ";
    std::cout << std::endl;
    return 0;
}