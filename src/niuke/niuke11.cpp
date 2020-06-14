#include <iostream>
#include <vector>

int minNumberInRotateArray(std::vector<int> array)
{
    if (array.size() == 0)
        return 0;
    int p1 = 0, p2 = array.size() - 1;
    if(array[p1]<array[p2])
        return array[p1];
    int mid = (p1+p2)/2;
    while(p1<p2){
        if((p2-p1)==1){
            return array[p2];
        }
        if(array[mid]>array[p2]){
            p1=mid;
        }
        else if(array[mid]<array[p2]){
            p2=mid;
        }
        // 这个else是为了避免这样的测试用例{1,0,1,1,1},否则会陷入死循环
        else
            ++p1;
        mid=(p1+p2)/2;
    }
    return array[p2];
}


//  int minNumberInRotateArray(vector<int> nums) {
//      if (rotateArray.empty()) return 0;
        // int left = 0, right = rotateArray.size() - 1;
         
        // while (left < right)
        // {            
        //     int mid = (right + left) / 2;
        //     //如果左半数组为有序数组
        //     if (rotateArray[left] < rotateArray[mid])
        //         left = mid;
        //     //如果右半数组为有序数组
        //     else if (rotateArray[mid] < rotateArray[right])
        //         right = mid;
        //     //否则，rotateArray[left] == rotateArray[mid] == rotateArray[right]
        //     else
        //         ++left;
        // }
        // return rotateArray[left];   
//     }
int main()
{
    std::vector<int> vec = {2, 3, 4, 5, 6, 7, 1};
    int min = 0;
    min = minNumberInRotateArray(vec);
    std::cout << "minimal number of rotate array is: " << min << std::endl;
    // int a=0, b=3;
    // std::cout << (a+b)/2<<std::endl;
    return 0;
}