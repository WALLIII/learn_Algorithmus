#include <iostream>
#include <vector>

void moveZeroes(std::vector<int> &nums)
{
    if(nums.size()<=1)
        return;
    int fast=0, low=0;
    for(fast=0; fast<nums.size();++fast){
        if(nums[fast]!=0){
            nums[low]=nums[fast];
            low++;
        }
    }
    for(int i=low;i<nums.size();++i){
        nums[i]=0;
    }
}
int main()
{
    std::vector<int> nums={1,0,3,24,0};
    moveZeroes(nums);
    for(auto a:nums)
        std::cout<<a<<"  ";
    std::cout<<std::endl;
    return 0;
}