#include <iostream>
#include <vector>
#include <set>
// 利用multiset
// std::vector<int> GetLeastNumbers_Solution(std::vector<int> input, int k)
// {
//     std::vector<int> res;
//     int size = input.size();
//     if (size < k || k <= 0 || size <= 0)
//         return res;
//     std::multiset<int, std::greater<int>> heap;
//     std::vector<int>::iterator it = input.begin();
//     for (; it != input.end(); it++)
//     {
//         if (heap.size() < k)
//         {
//             heap.insert(*it);
//         }
//         else
//         {
//             // heap.begin():最大堆的第一个数是最大的那个数
//             std::multiset<int, std::greater<int>>::iterator heap_it = heap.begin();
//             if (*it < *heap_it)
//             {
//                 heap.erase(heap_it);
//                 heap.insert(*it);
//             }
//         }
//     }
//     return std::vector<int>(heap.begin(), heap.end());
// }
// 用最大堆
// std::vector<int> GetLeastNumbers_Solution(std::vector<int> input, int k)
// {
//     int size = input.size();
//     if (size < k || k <= 0 || size <= 0)
//         return std::vector<int>();
//     std::vector<int> res(input.begin(), input.begin() + k);
//     std::make_heap(res.begin(), res.end());
//     for (int i = k; i < size; ++i)
//     {
//         if(input[i]<res[0]){
//             // 把当前最大堆中的最大元素（本应该在堆首的）移到堆尾，其他元素位置不变。
//             std::pop_heap(res.begin(), res.end());
//             res.pop_back();
//             res.push_back(input[i]);
//             // 现在新元素加入堆尾了，调用push_heap，调整元素位置
//             std::push_heap(res.begin(), res.end());
//         }
//     }
//     return res;
// }
int Partition(std::vector<int> &arr, int first, int last)
{
    int tmp = arr[first];
    while (first < last)
    {
        while (first < last && arr[last] >= tmp)
            last--;
        std::swap(arr[first], arr[last]);
        while (first < last && arr[first] <= tmp)
            first++;
        std::swap(arr[first], arr[last]);
    }
    return first;
}

std::vector<int> GetLeastNumbers_Solution(std::vector<int> input, int k)
{
    std::vector<int> res;
    if (input.size() <= 0 || k > input.size() || k <= 0)
    {
        return res;
    }
    int len = input.size();
    int first = 0, last = len - 1;
    int tmpIndex = Partition(input, first, last);

    while (tmpIndex != k)
    {
        if (tmpIndex < k)
        {
            first = tmpIndex + 1;
            tmpIndex = Partition(input, first, last);
        }
        if (tmpIndex > k)
        {
            last = tmpIndex - 1;
            tmpIndex = Partition(input, first, last);
        }
    }
    for (int i = 0; i < tmpIndex; ++i)
    {
        res.push_back(input[i]);
    }
    return res;
}

int main()
{
    std::vector<int> input = {4, 5, 1, 6, 2, 7, 3, 8};
    std::vector<int> res;
    res = GetLeastNumbers_Solution(input, 10);
    for (auto a : res)
    {
        std::cout << a << "  ";
    }
    std::cout << std::endl;
    std::cout << "input:  " << std::endl;
    for (auto a : input)
    {
        std::cout << a << "  ";
    }
    std::cout << std::endl;
    return 0;
}
