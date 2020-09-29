#include <deque>
#include <iostream>
#include<vector>

std::vector<int> maxInWindows(const std::vector<int> &num, unsigned int size)
{
    std::vector<int> res;
    std::deque<int> s;
    for (unsigned int i = 0; i < num.size(); ++i)
    {
        while (s.size() && num[s.back()] <= num[i]) //从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
            s.pop_back();
        while (s.size() && i - s.front() + 1 > size) //当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
            s.pop_front();
        s.push_back(i);            //把每次滑动的num下标加入队列
        if (size && i + 1 >= size) //当滑动窗口首地址i大于等于size时才开始写入窗口最大值
            res.push_back(num[s.front()]);
    }
    return res;
}

int main(){
    std::vector<int> num={1,3,-1,-3,7,3,6,1};
    std::vector<int> res=maxInWindows(num,3);
    for(auto a:res){
        std::cout<<a<<"  ";
    }
    std::cout<<std::endl;
    return 0;
}