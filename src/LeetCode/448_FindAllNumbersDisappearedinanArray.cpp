#include <iostream>
#include <vector>

std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
{
    std::vector<int> ans;
    if (nums.size() <= 0)
        return ans;
    for (int i = 0; i < nums.size(); ++i)
    {
        // 找到当前值nums[i]在数组中应该对应的索引，加入nums[i]=4，它对应的索引就是3
        // 对nums.size()取余：因为找到nums[i]索引位置后，要加上nums.size()，我们要知道他本来应该有的值。
        int index = (nums[i] - 1) % nums.size();
        // 假设缺少的数字是5，那么index=4的位置不会被加上nums.size()，该索引处的值小于nums.size()
        nums[index] = nums[index] + nums.size();
    }
    for(int i=0;i<nums.size();++i){
        if(nums[i]<=nums.size()){
            ans.push_back(i+1);
        }
    }
    return ans;
}
int main()
{
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> res = findDisappearedNumbers(nums);
    std::cout << "res:  " << std::endl;
    for (auto a : res)
        std::cout << a << "  ";
    std::cout << std::endl;
    return 0;
}