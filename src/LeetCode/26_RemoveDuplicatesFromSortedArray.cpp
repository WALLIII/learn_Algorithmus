#include <vector>
#include <iostream>

int removeDuplicates(std::vector<int> &nums)
{
    if (nums.size() <= 0)
        return 0;
    if(nums.size()==1)
        return 1;
    int p1 = 0, p2 = 0;
    while (p2 < nums.size())
    {
        while(nums[p2]==nums[p1]){
            if(p2>=nums.size()-1)
                return p1+1;
            ++p2;
        }
        p1++;
        int tmp=nums[p2];
        nums[p1]=nums[p2];
        ++p2;
    }
    return p1+1;
}

int main()
{
    std::vector<int> nums = {1,1,2};
    int newLength = removeDuplicates(nums);
    std::cout << "new length:  " << newLength << std::endl;
    for (auto a : nums)
        std::cout << a << "   ";
    std::cout << std::endl;
    return 0;
}