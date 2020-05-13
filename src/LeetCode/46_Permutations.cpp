#include <iostream>
#include <vector>

void backtrack(std::vector<int> &nums, int start,
               std::vector<int> &track,
               std::vector<std::vector<int>> &ans)
{
    if(start>=nums.size()){
        ans.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); ++i)
    {
        std::swap(nums[start],nums[i]);
        backtrack(nums, start+1, track, ans);
        std::swap(nums[i],nums[start]);
    }
}

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    std::vector<std::vector<int>> ans;
    std::vector<int> track;
    backtrack(nums, 0, track, ans);
    return ans;
}
int main()
{
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> ans;
    ans = permute(nums);
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