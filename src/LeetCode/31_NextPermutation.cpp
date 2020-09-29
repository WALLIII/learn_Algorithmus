#include <vector>
#include <iostream>
using namespace std;

void swapArray(vector<int> &nums, int s, int e)
{
    if (s > e)
        return;
    int i = s, j = e;
    while (i <= j)
    {
        swap(nums[i++], nums[j--]);
    }
}

void nextPermutation(vector<int> &nums)
{
    if (nums.size() <= 1)
        return;
    // 从后往前找第一个相邻的逆序对
    int i = 0;
    for (i = nums.size() - 2; i >= 0; --i)
    {
        if (nums[i] < nums[i + 1])
            break;
    }
    cout<<"i:  "<<i<<endl;
    //如果i==-1，说明整个nums是降序排列的，就要全部翻转为升序序列
    if (i == -1)
    {
       
        swapArray(nums, 0, nums.size() - 1);
        return;
    }
    // nums[i]<nums[j]

    // 现在要在[j,end]区间内从后往前找到第一个大于nums[i]的元素nums[k]
    for (int k = nums.size() - 1; k >= i + 1; --k)
    {
        if (nums[k] > nums[i])
        {
            cout<<"k: "<<k<<endl;
            swap(nums[k], nums[i]);
            swapArray(nums, i + 1, nums.size() - 1);
            break;
        }
    }
    return;
}
int main()
{
    std::vector<int> num = {2,2,0,4,3,1};
    nextPermutation(num);
    for(auto a:num)
        cout<<a<<"  ";
    cout<<endl;
    
    return 0;
}