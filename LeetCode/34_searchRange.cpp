#include <vector>
#include <iostream>
using namespace std;
int left_bound(vector<int> &nums, int target)
{
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
        {
            hi = mid - 1;
        }
        else if (nums[mid] > target)
        {
            hi = mid - 1;
        }
        else if (nums[mid] < target)
        {
            lo = mid + 1;
        }
    }
    if (lo >= nums.size() || nums[lo] != target)
        return -1;
    return lo;
}

int right_bound(vector<int> &nums, int target)
{
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
        {
            lo = mid + 1;
        }
        else if (nums[mid] > target)
        {
            hi = mid - 1;
        }
        else if (nums[mid] < target)
        {
            lo = mid + 1;
        }
    }
    if (hi < 0 || nums[hi] != target)
        return -1;
    return hi;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> res = {-1, -1};
    if (nums.size() <= 0)
        return res;
    int left = left_bound(nums, target);
    int right = right_bound(nums, target);
    res[0] = left;
    res[1] = right;
    return res;
}
int main()
{
    std::vector<int> nums{5, 7, 7, 8, 8, 10};

    std::vector<int> ans;
    ans = searchRange(nums, 8);

    for (auto tmp : ans)
    {
        std::cout << tmp << "    ";
    }
    std::cout << std::endl;
}