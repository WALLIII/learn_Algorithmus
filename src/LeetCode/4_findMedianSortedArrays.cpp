#include <vector>
#include <iostream>
// 高级方法
// double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
// {
//     int n = nums1.size();
// 		int m = nums2.size();

// 		if (n > m)  //保证数组1一定最短
// 		{
// 			return findMedianSortedArrays(nums2, nums1);
// 		}

// 		// Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
// 		int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度

// 		while (lo <= hi)   //二分
// 		{
// 			c1 = (lo + hi) / 2;  //c1是二分的结果
// 			c2 = m + n - c1;

// 			LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
// 			RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
// 			LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
// 			RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

// 			if (LMax1 > RMin2)
// 				hi = c1 - 1;
// 			else if (LMax2 > RMin1)
// 				lo = c1 + 1;
// 			else
// 				break;
// 		}
// 		return (std::max(LMax1, LMax2) + std::min(RMin1, RMin2)) / 2.0;
// }
// 自己的方法，开辟一个数组
double findMedianSortedArrays(std::vector<int> &nums1, 
								std::vector<int> &nums2)
{
    int l1 = nums1.size(), l2 = nums2.size(), len = l1 + l2;
    int mid = len / 2, p1 = 0, p2 = 0, index = 0;
    std::vector<int> arr(mid + 1, 0);
    while (index <= mid && p1 < l1 && p2 < l2)
    {
        if (p1 < l1 && p2 < l2 && nums1[p1] > nums2[p2])
        {
            arr[index] = nums2[p2];
            p2++;
        }
        else if (p1 < l1 && p2 < l2 && nums1[p1] <= nums2[p2])
        {
            arr[index] = nums1[p1];
            p1++;
        }

        index++;
    }
    // std::cout << "p1: " << p1 << " p2: " << p2 << " index: " << index << std::endl;
    if (index-1 < mid)
    {

        if (p1 < l1)
        {
            for (int i = index; i <= mid; ++i)
            {
                arr[i] = nums1[p1];
                ++p1;
            }
        }
        if (p2 < l2)
        {
            for (int i = index; i <= mid; ++i)
            {
                arr[i] = nums2[p2];
                ++p2;
            }
        }
    }
    // for (auto a : arr)
    //     std::cout << a << "   ";
    // std::cout << std::endl;
    if (len % 2 == 0)
    {
        return (double)(arr[mid - 1] + arr[mid]) / 2.0;
    }
    if (len % 2 == 1)
        return (double)arr[mid];
}
int main(){
    std::vector<int> num1={1,4,7,9};
    std::vector<int> num2={2,3,5}
    std::cout<<findMedianSortedArrays(num1,num2)<<std::endl;
    return 0;
}