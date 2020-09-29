#include <vector>
#include <iostream>

//程序的主体函数
int InversePairsCore(std::vector<int> &data, int *&copy, int start, int end)
{
    if (start == end)
        return 0;
    int mid = (start + end) / 2;
    int left = InversePairsCore(data, copy, start, mid);
    int right = InversePairsCore(data, copy, mid + 1, end);
    int count = 0;
    int p1 = mid, p2 = end;
    int copyIndex = end;
    while (p1 >= start && p2 >= mid + 1)
    {
        if (data[p1] > data[p2])
        {
            copy[copyIndex--] = data[p1--];
            // p2 - mid:表示p2所指的数组还剩下几个数，比如5 7 4 6这个情况，p2->6, p1->7，这个时候count要+2，即p2-mid
            count += (p2 - mid) % 1000000007;
        }
        else
        {
            copy[copyIndex--] = data[p2--];
        }
    }
    for (; p1 >= start; p1--)
    {
        copy[copyIndex--] = data[p1];
    }
    for (; p2 >= mid + 1; p2--)
    {
        copy[copyIndex--] = data[p2];
    }
    for (int i = start; i <= end; ++i)
    {
        data[i] = copy[i];
    }
    return (count + left + right) % 1000000007;
}

int InversePairs(std::vector<int> data)
{
    if (data.size() <= 1)
        return 0;
    int *copy = new int[data.size()];
    for (int i = 0; i < data.size(); ++i)
        copy[i] = 0;
    int res = InversePairsCore(data, copy, 0, data.size() - 1);
    delete[] copy;
    return res;
}

//补充一个从头开始归并的
int mergeSortCore(vector<int> &nums, vector<int> &copy, int s, int e)
{
    if (s >= e)
        return 0;
    int mid = (s + e) / 2;
    int left = mergeSortCore(nums, copy, s, mid);
    int right = mergeSortCore(nums, copy, mid + 1, e);
    int p1 = s, p2 = mid + 1, index = s;
    int count = 0;
    while (p1 <= mid && p2 <= e)
    {
        if (nums[p1] > nums[p2])
        {
            count += (mid - p1 + 1) % 1000000007;
            copy[index++] = nums[p2++];
        }
        else
        {
            copy[index++] = nums[p1++];
        }
    }
    while (p1 <= mid)
    {
        copy[index++] = nums[p1++];
    }
    while (p2 <= e)
    {
        copy[index++] = nums[p2++];
    }
    for (int i = s; i <= e; ++i)
        nums[i] = copy[i];
    return count + left + right;
}
int reversePairs(vector<int> &nums)
{
    if (nums.size() <= 0)
        return 0;
    vector<int> copy(nums);
    int res = mergeSortCore(nums, copy, 0, nums.size() - 1);
    return res;
}

int main()
{
    std::vector<int> arr = {7, 5, 6, 4};
    std::cout << InversePairs(arr) << std::endl;
    return 0;
}