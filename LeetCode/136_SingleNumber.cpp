#include <queue>
#include <vector>
#include <iostream>

int singleNumber(std::vector<int> &nums)
{
    int tmp=0;
    for(auto a:nums){
        tmp=tmp^a;
    }
    return tmp;
}

int main()
{
    std::vector<int> nums = {4, 3, 4, 3, 6, 7, 7, 8, 6};
    std::cout << singleNumber(nums) << std::endl;
    return 0;
}