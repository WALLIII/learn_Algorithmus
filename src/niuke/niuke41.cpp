#include"utils/DataStream.h"
#include<iostream>

int main(){
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
    std::vector<int> max={};
    std::vector<int> min={};
    o1.SetHeap(max, min);
    o1.Insert(7);
    double res = o1.GetMedian();
    std::cout<<"Res:  "<<res<<std::endl;

    return 0;
}