#include "../Utils/DataStream.h"
#include <iostream>

// void DataStream::Insert(int num)
// {
//     // 当前两个堆的数量之和为偶数，要给最小堆+1
//     if (((max.size() + min.size()) & 1) == 0)
//     {
//         // 如果新来的数字小于最小堆的最大值，就把它加入最大堆，最大堆拿出堆顶放到最小堆
//         if (max.size() && num < max[0])
//         {
//             max.push_back(num);
//             push_heap(max.begin(), max.end(), less<int>());
//             num = max[0];
//             // pop_heap会把堆顶元素移到堆尾，即数组的尾部
//             pop_heap(max.begin(), max.end(), less<int>());
//             max.pop_back();
//         }
//         min.push_back(num);
//         push_heap(min.begin(), min.end(), greater<int>());
//     }
//     //当前两个堆的数量之和为奇数，要给最大堆
//     else
//     {
//         // 如果新来的数字大于最大堆的堆顶，就把它加入最小堆，最小堆里拿出堆顶放到最大堆
//         if (min.size() && num > min[0])
//         {
//             min.push_back(num);
//             push_heap(min.begin(), min.end(), greater<int>());
//             num = min[0];
//             pop_heap(min.begin(), min.end(), greater<int>());
//             min.pop_back();
//         }
//         max.push_back(num);
//         push_heap(max.begin(), max.end(), less<int>());
//     }
// }
// double DataStream::GetMedian()
// {
//     int size = min.size() + max.size();
//     double median;
//     if (size <= 0)
//     {
//         throw "No numbers!";
//     }
//     else if ((size & 1) == 0)
//     {
//         median = ((double)max[0] + (double)min[0]) / 2;
//     }
//     else
//     {
//         median = (double)min[0];
//     }
//     return median;
// }

int main()
{
    // std::vector<int> max={6,2,3,4,8,1};
    // std::make_heap(max.begin(), max.end(), std::less<int>());
    // std::push_heap(max.begin(), max.end(),std::less<int>());
    // std::cout<<"before pop_heap:   ";
    // for(auto a: max){
    //     std::cout<<a<<"  ";
    // }
    // std::cout<<std::endl;
    // std::pop_heap(max.begin(), max.end(),std::less<int>());
    // max.pop_back();
    // std::cout<<"push_heap result:   ";
    // for(auto a: max){
    //     std::cout<<a<<"  ";
    // }
    // std::cout<<std::endl;
    // std::cout<<"max[0]: "<<max[0]<<std::endl;
    DataStream o1;
    std::vector<int> max = {};
    std::vector<int> min = {};
    o1.SetHeap(max, min);
    o1.Insert(7);
    o1.Insert(6);
    std::cout << "Res:  " << o1.GetMedian() << std::endl;

    o1.Insert(8);
    std::cout << "Res:  " << o1.GetMedian() << std::endl;

    o1.Insert(3);
    o1.Insert(1);
    o1.Insert(10);
    // double res = o1.GetMedian();
    std::cout << "Res:  " << o1.GetMedian() << std::endl;

    return 0;
}