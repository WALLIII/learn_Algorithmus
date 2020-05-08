#include <vector>
#include <iostream>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> ans;
    if (nums.size() <= 0)
        return ans;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i)
    {
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int p1 = i + 1, p2 = nums.size() - 1;
        while (p1 < p2)
        {
            int currSum = nums[i] + nums[p1] + nums[p2];
            // std::cout<<"currSum:  "<<currSum<<std::endl;
            if (currSum == 0)
            {
                std::vector<int> tmp{nums[i], nums[p1], nums[p2]};
                // for (auto a : tmp)
                // {
                //     std::cout << a << "    ";
                // }
                // std::cout << std::endl;
                ans.push_back(tmp);
                while (p1 < p2 && nums[p1] == nums[p1 + 1])
                {
                    p1++;
                }
                while (p1 < p2 && nums[p2] == nums[p2 - 1])
                {
                    p2--;
                }
                ++p1;
                --p2;
            }
            else if (currSum < 0)
                ++p1;
            if (currSum > 0)
                --p2;
        }
    }
    return ans;
}

int main()
{
    std::vector<int> nums{-1, 0, 1, 2, -1, -4};

    std::vector<std::vector<int>> ans;
    ans = threeSum(nums);
    std::cout<<ans.size()<<std::endl;
    std::cout<<ans[0].size()<<std::endl;
    for (auto tmp : ans)
    {
        for (auto a : tmp)
        {
            std::cout << a << "    ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}