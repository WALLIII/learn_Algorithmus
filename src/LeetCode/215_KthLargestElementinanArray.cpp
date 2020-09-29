#include <queue>
#include <vector>
#include <iostream>

using namespace std;
// 小顶堆/最小堆
int findKthLargest(std::vector<int> &nums, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (auto n : nums)
    {
        if (pq.size() >= k && pq.top() > n)
            continue;
        pq.push(n);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}
//分治法

int Partition(vector<int> &nums, int l, int r)
{

    int tmp = nums[l];
    while (l < r)
    {
        while (l < r && nums[r] > tmp)
            --r;
        swap(nums[l], nums[r]);
        while (l < r && nums[l] < tmp)
            ++l;
        swap(nums[r], nums[l]);
    }
    return l;
}

int randomquickSort(vector<int> &nums, int l, int r)
{
    int ran = (rand() % (r-l + 1)) + l;
    swap(nums[l], nums[ran]);
    return Partition(nums, l, r);
}
int findKthLargest(vector<int> &nums, int k)
{
    if (nums.size() <= 0)
        return 0;
    int l = 0, r = nums.size() - 1;
    int index = Partition(nums, l, r);
    while (index != nums.size() - k )
    {
        if (index < nums.size() - k )
        {
            l = index + 1;
            index = randomquickSort(nums, l, r);
        }
        else if (index > nums.size() - k )
        {
            r = index - 1;
            index = randomquickSort(nums, l, r);
        }
    }
    for(auto a:nums)
        cout<<a<<"  ";
    cout<<endl;
    return nums[index];
}


int main()
{
    std::vector<int> nums = {5, 4, 3, 7, 6};
    std::cout << findKthLargest(nums, 2) << std::endl;
    return 0;
}