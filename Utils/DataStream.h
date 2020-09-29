#ifndef _DATA_STREAM_H
#define _DATA_STREAM_H

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

class DataStream
{
private:
    std::vector<int> min;
    std::vector<int> max;

public:
    void SetHeap(std::vector<int> maxVec, std::vector<int> minVec){
        min = minVec;
        max = maxVec;
        // 建立最大堆
        std::make_heap(max.begin(), max.end(), std::less<int>());
        // 建立最小堆
        std::make_heap(min.begin(), min.end(), std::greater<int>());
    }
    void Insert(int num);
    double GetMedian();
};

void DataStream::Insert(int num)
{
    // max.size()+min.size(): even number，往最小堆插入
    if (((max.size() + min.size()) & 1) == 0)
    {
        // max[0]: maximum of max heap
        if (max.size() > 0 && num < max[0])
        {
            max.push_back(num);
            std::push_heap(max.begin(), max.end(), std::less<int>());
            num = max[0];
            std::pop_heap(max.begin(), max.end(), std::less<int>());
            max.pop_back();
        }
        min.push_back(num);
        std::push_heap(min.begin(), min.end(), std::greater<int>());
    }
    // max.size()+min.size(): odd number，往最大堆插入
    else
    {
        if (min.size() > 0 && num > min[0])
        {
            min.push_back(num);
            std::push_heap(min.begin(), min.end(), std::greater<int>());
            num = min[0];
            std::pop_heap(min.begin(), min.end(), std::greater<int>());
            min.pop_back();
        }
        max.push_back(num);
        std::push_heap(max.begin(), max.end(), std::less<int>());
    }

}
double DataStream::GetMedian()
{
    int size = min.size()+max.size();
    double median;
    if(size<=0){
        throw "No numbers!";
    }
    else if((size&1)==0){
        median = ((double)max[0]+(double)min[0])/2;
    }
    else{
        median = (double)min[0];
    }
    return median;
}

#endif // _DATA_STREAM_H