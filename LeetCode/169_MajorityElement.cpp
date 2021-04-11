#include <vector>
#include <iostream>
#include <unordered_map>

// int majorityElement(std::vector<int> &nums)
// {
//     std::sort(nums.begin(), nums.end());
//     int len = nums.size();
//     return nums[len / 2];
// }
int majorityElement(std::vector<int> &nums){
    std::unordered_map<int,int> hash(0);
    for(auto a:nums){
        hash[a]++;
        if(hash[a]>(nums.size()/2))
            return a;
    }
    return INT_MIN;
}
int main()
{
    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    std::cout << majorityElement(nums) << std::endl;
    return 0;
}