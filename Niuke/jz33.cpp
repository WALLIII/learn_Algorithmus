#include <iostream>
#include <vector>
// bool isUglyNumber(int a){
//     while(a%2==0)
//         a/=2;
//     while(a%3==0)
//         a/=3;
//     while(a%5==0)
//         a/=5;
//     return (a==1)?true:false;
// }

// int GetUglyNumber_Solution(int index){
//     if(index<=0)
//         return 0;
//     int uglyFounded=0, number=0;
//     while(uglyFounded<index){
//         ++number;
//         if(isUglyNumber(number))
//             ++uglyFounded;
//     }
//     return number;
// }
int GetUglyNumber_Solution(int index)
{
    if (index < 7)
        return index;
    std::vector<int> arr;
    int p2=0, p3=0, p5=0, newNum=1;
    arr.push_back(newNum);
    while(arr.size()<index){
        newNum=std::min(arr[p2]*2, std::min(arr[p3]*3, arr[p5]*5));
        if(arr[p2]*2==newNum) p2++;        
        if(arr[p3]*3==newNum) p3++;
        if(arr[p5]*5==newNum) p5++;
        arr.push_back(newNum);
    }
    return arr[index-1];
}
int main()
{
    std::cout << "ugly number:  " << GetUglyNumber_Solution(15) << std::endl;

    return 0;
}