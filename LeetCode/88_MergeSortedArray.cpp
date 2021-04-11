#include <vector>
#include <iostream>

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    if (nums1.size() <= 0 || nums2.size() <= 0)
        return;
    int tail = m + n - 1;
    m--;
    n--;
    while (m >= 0 && n >= 0)
    {
        if (nums1[m] >= nums2[n])
        {
            nums1[tail] = nums1[m];
            m--;
        }
        else
        {
            nums1[tail] = nums2[n];
            n--;
        }
        tail--;
    }
    if (m == -1)
    {
        for (int i = n; i >= 0; --i)
        {
            nums1[tail] = nums2[i];
            tail--;
        }
    }
    else if (n == -1)
    {

        for (int i = m; i >= 0; --i)
        {
            nums1[tail] = nums1[i];
            tail--;
        }
    }
}

int main()
{
    std::vector<int> nums1 = {1,2,3, 0, 0, 0};
    std::vector<int> nums2 = {2,5,6};
    merge(nums1, 3, nums2, 3);
    for (auto a : nums1)
    {
        std::cout << a << "  ";
    }
    std::cout << std::endl;
}