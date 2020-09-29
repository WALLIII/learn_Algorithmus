#include <vector>
#include <iostream>
using namespace std;
// 自己写的，在判断左边是否有序的时候，不能用nums[l]<nums[mid-1]，要考虑到数组只有一个数字的情况{1}
// int search(vector<int> &nums, int target) {
//     if(nums.size()<=0)
//         return -1;
//     int l=0, r=nums.size()-1, mid=nums.size()/2;
//     while(l<=r){
//         if(target==nums[mid])
//             return mid;
//         // 如果没有找到，先判断左边是否有序，两边必定有一边有序
//         // 如果左边有序
//         if(nums[l]<nums[mid-1]){
//             // 就判断target是否在左边的数组中
//             // 如果在左边数组中，就在左边数组中搜索，如果不再就在右边数组中搜索
//             if(target>=nums[l]&&target<=nums[mid-1]){
//                 r=mid-1;
//             }
//             else{
//                 l=mid+1;
//             }
//         }
//         // 如果左边数组无序，右边数组一定有序
//         else{
//             // 判断target是否在右边数组中
//             if(target>=nums[mid+1]&&target<=nums[r]){
//                 l=mid+1;
//             }
//             // 如果不在的话，就肯定在左边数组
//             else{
//                 r=mid-1;
//             }
//         }
//         mid=(l+r)/2;
//     }
//     return -1;
// }
int search(vector<int> &nums, int target)
{
    if (nums.empty())
        return -1;
    if (nums.size() == 1)
        return target == nums[0] ? 0 : -1;

    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        // left is sorted
        if (nums[left] <= nums[mid])
        {
            if (target >= nums[left] && target <= nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        // else right array is sorted
        else
        {
            if (target > nums[mid] && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    std::vector<int> num = {1};
    cout << search(num, 0) << endl;

    return 0;
}