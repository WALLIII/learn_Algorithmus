#include <iostream>
#include <vector>
void backtrack(std::vector<int> &nums, int start,
               std::vector<int> &track,
               std::vector<std::vector<int>> &ans)
{
    ans.push_back(track);
    for (int i = start; i < nums.size(); ++i)
    {
        track.push_back(nums[i]);
        backtrack(nums, i + 1, track, ans);
        track.pop_back();
    }
}

std::vector<std::vector<int>> subsets(std::vector<int> &nums)
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
    ans = subsets(nums);
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