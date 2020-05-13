#include <iostream>
#include <vector>
// dp1/greedy algorithm:
// int maxSubArray(std::vector<int> &nums)
// {
//     if(nums.size()<=0)
//         return INT_MIN;
//     if(nums.size()==1)
//         return nums[0];
//     int currSum=nums[0], maxSum=nums[0];
//     for(int i=1;i<nums.size();++i){
//         if(currSum<=0){
//             currSum=nums[i];
//             maxSum=maxSum>currSum?maxSum:currSum;
//         }
//         else{
//             currSum+=nums[i];
//             maxSum=maxSum>currSum?maxSum:currSum;
//         }
//     }
//     return maxSum;
// }
// dp2:
// int maxSubArray(std::vector<int> &nums)
// {
//     std::vector<int> dp(nums.size());
//     if (nums.size() <= 0)
//         return INT_MIN;
//     if (nums.size() == 1)
//         return nums[0];
//     dp[0]=nums[0];
//     int max=nums[0];
//     for (int i = 1; i < nums.size(); ++i)
//     {
//         if(dp[i-1]<=0){
//             dp[i]=nums[i];
//         }
//         else{
//             dp[i]=dp[i-1]+nums[i];
//         }
//         max=max>dp[i]?max:dp[i];
//     }
//     return max;
// }
// 分治
int findMaxCrossingSubarray(std::vector<int> &nums, int left, int mid, int right);
int maxSubArrayHelper(std::vector<int> &nums, int left, int right);
int maxSubArray(std::vector<int> &nums)
{
    //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
    int result = INT_MIN;
    int numsSize = int(nums.size());
    result = maxSubArrayHelper(nums, 0, numsSize - 1);
    return result;
}

int maxSubArrayHelper(std::vector<int> &nums, int left, int right)
{
    if (left == right)
    {
        return nums[left];
    }
    int mid = (left + right) / 2;
    int leftSum = maxSubArrayHelper(nums, left, mid);
    //注意这里应是mid + 1，否则left + 1 = right时，会无线循环
    int rightSum = maxSubArrayHelper(nums, mid + 1, right);
    int midSum = findMaxCrossingSubarray(nums, left, mid, right);
    int result = std::max(leftSum, rightSum);
    result = std::max(result, midSum);
    return result;
}

int findMaxCrossingSubarray(std::vector<int> &nums, int left, int mid, int right)
{
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= left; i--)
    {
        sum += nums[i];
        leftSum = std::max(leftSum, sum);
    }

    int rightSum = INT_MIN;
    sum = 0;
    //注意这里i = mid + 1，避免重复用到nums[i]
    for (int i = mid + 1; i <= right; i++)
    {
        sum += nums[i];
        rightSum = std::max(rightSum, sum);
    }
    return (leftSum + rightSum);
}

int main()
{
    std::vector<int> nums = {-2, 1};
    std::cout << maxSubArray(nums) << std::endl;
    return 0;
}