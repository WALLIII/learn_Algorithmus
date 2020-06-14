#include <iostream>
#include <vector>
#include<stack>

// bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV)
// {
//     int pushLen=pushV.size(), popLen=popV.size();
//     if(pushLen==0 || popLen==0)
//         return false;
//     int pushIndex=1, popIndex=0;
//     std::stack<int> sk;
//     sk.push(pushV[0]);
//     while(!sk.empty()){
//         if(pushIndex<pushLen && sk.top()!=popV[popIndex]){
//             sk.push(pushV[pushIndex]);
//             pushIndex++;
//         }
//         else if(sk.top()==popV[popIndex]){
//             sk.pop();
//             popIndex++;
//         }
//         else if(sk.top()!=popV[popIndex]&&pushIndex==pushLen)
//             return false;
//     }
//     return true;
// }
bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV){
    int pushLen=pushV.size(), popLen=popV.size();
    if(pushLen==0 || popLen==0)
        return false;
    std::stack<int> sk;
    for(int i=0, j=0;i<pushLen;){
        sk.push(pushV[i++]);
        while(j<popLen && sk.top()==popV[j]){
            sk.pop();
            j++;
        }
    }
    return sk.empty();
}
int main()
{
    std::vector<int> push = {1, 2, 3, 4, 5};
    std::vector<int> pop = {4, 5, 3,1,2};
    if (IsPopOrder(push, pop))
    {
        std::cout << "pop series is pop order of push series!" << std::endl;
    }
    else
    {
        std::cout << "no..." << std::endl;
    }
    return 0;
}
