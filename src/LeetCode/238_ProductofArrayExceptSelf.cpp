#include <vector>
#include <iostream>
std::vector<int> productExceptSelf(std::vector<int> &nums)
{
    std::vector<int> ans(nums.size());
    int prod = 1;
    for (int i = 0; i < nums.size(); ++i)
    {
        ans[i] = prod;
        prod *= nums[i];
    }
    for (int i = nums.size() - 1, prod = 1; i >= 0; i--)
    {
        ans[i] = ans[i] * prod;
        prod = prod * nums[i];
    }
    return ans;
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> ans = productExceptSelf(nums);
    for (auto a : ans)
        std::cout << a << "  ";
    std::cout << std::endl;
    return 0;
}