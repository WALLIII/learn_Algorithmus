#include <vector>
#include <iostream>

int threeSumClosest(std::vector<int> &nums, int target)
{

    if (nums.size() < 3)
        return INT_MIN;
    std::sort(nums.begin(), nums.end());
    for (int a : nums)
        std::cout << a << "  ";
    std::cout << std::endl;
    int ans = nums[0]+nums[1]+nums[2];
    for (int i = 0; i < nums.size() - 2; ++i)
    {
        int p1 = i + 1, p2 = nums.size() - 1;
        while (p1 < p2)
        {
            int currSum = nums[i] + nums[p1] + nums[p2];
            if (abs(currSum - target) < abs(ans-target))
            {
                ans = currSum;
            }
            if (ans == target)
                return ans;
            else if (currSum < target)
                p1++;
            else
                p2--;
        }
    }
    return ans;
}
// int threeSumClosest(std::vector<int> &nums, int target)
// {
    // std::sort(nums.begin(), nums.end());
    // int ans = nums[0] + nums[1] + nums[2];
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     int st = i + 1, ed = nums.size() - 1;
    //     while (st < ed)
    //     {
    //         int sum = nums[st] + nums[ed] + nums[i];
    //         if (abs(target - sum) < abs(target - ans))
    //             ans = sum;
    //         if (sum == target)
    //             return ans;
    //         else if (sum < target)
    //             st++;
    //         else
    //             ed--;
    //     }
    // }
    // return ans;
// }

int main()
{
    std::vector<int> nums{-1, 2, 1, -4};

    int ans;
    ans = threeSumClosest(nums, 1);
    std::cout << "closest answer:  " << ans << std::endl;
    return 0;
}