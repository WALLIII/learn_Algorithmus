#include <iostream>
#include <vector>
#include<unordered_set>
void backtrack(std::vector<int> &nums, int start,
               std::vector<std::vector<int>> &ans)
{
    if(start>=nums.size()){
        ans.push_back(nums);
        return;
    }
    std::unordered_set<int> uniq;
    for (int i = start; i < nums.size(); ++i)
    {
        // 如果为真，说明nums[i]这个元素之前枚举过了，跳过
        if(uniq.count(nums[i])){
            continue;
        }
        std::swap(nums[start],nums[i]);
        backtrack(nums, start+1, ans);
        std::swap(nums[i],nums[start]);
        // 走到这边，nums[i]放在首位的情况被搜索过了，下一次遇到nums[i]一样的数就要跳过
        uniq.insert(nums[i]);
    }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums)
{
    std::vector<std::vector<int>> ans;
    backtrack(nums, 0, ans);
    return ans;
}
int main()
{
    std::vector<int> nums = {1, 1,2};
    std::vector<std::vector<int>> ans;
    ans = permuteUnique(nums);
    for (auto sub : ans)
    {
        for (auto a : sub)
        {
            std::cout << a << "  ";
        }
        std::cout << std::endl;
    }
    return 0;
}