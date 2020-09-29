#include <vector>
#include <iostream>

// int FindGreatestSumOfSubArray(std::vector<int> array)
// {
//     int len = array.size();
//     int maximum = INT_MIN;
//     int currSum = 0;
//     if (len <= 0)
//         return maximum;
//     for (int i = 0; i < len; ++i)
//     {
//         if (currSum <= 0)
//         {
//             currSum = array[i];
//         }
//         else
//         {
//             currSum += array[i];
//         }
//         if (currSum > maximum)
//         {
//             maximum = currSum;
//         }
//     }
//     return maximum;
// }

int FindGreatestSumOfSubArray(std::vector<int> nums){
     if(nums.size()<=0)
            return INT_MIN;
       vector<int> dp;
        dp[0]=nums[0];
        int max=INT_MAX;
        for(int i=1;i<nums.size();++i){
            dp[i]=std::max(dp[i-1]+nums[i], nums[i]);
            max=max>dp[i]?max:dp[i];
        }
        return max;

}

int main(){
    std::vector<int> array = {1,-2,3,10,-4,7,2,-5};
    std::cout<<FindGreatestSumOfSubArray(array)<<std::endl;
    return 0;
}