#include <iostream>
#include <vector>

// int minNumberInRotateArray(std::vector<int> rotateArray)
// {
//     int arrayLength = rotateArray.size();
//     if (arrayLength <= 0)
//     {
//         return -1;
//     }
//     if (rotateArray[0] <= rotateArray[arrayLength - 1])
//     {
//         return rotateArray[0];
//     }

//     int index1 = 0;
//     int index2 = arrayLength - 1;
//     int midIndex = index1;
//     // while (rotateArray[index2] < rotateArray[index1])
//     while (index1 < index2)
//     {
//         if ((index2 - index1) == 1)
//         {
//             midIndex = index2;
//             break;
//         }
//         midIndex = (index1 + index2) / 2;
//         if (rotateArray[midIndex] < rotateArray[index2])
//         {
//             index2 = midIndex;
//         }
//         else if (rotateArray[midIndex] > rotateArray[index1])
//         {
//             index1 = midIndex;
//         }
//     }
//     return rotateArray[midIndex];
// }

int minNumberInRotateArray(std::vector<int> array)
{
    if (array.size() == 0)
        return 0;
    int first = 0, last = array.size() - 1;
    int mid = (first + last) / 2;
    while (array[first] >= array[last])
    {
        if (last - first == 1)
            return array[last];
        if (array[first] == array[mid] && array[mid] == array[last])
        {
            // linear search
            int min = array[first];
            for (int i = first + 1; i <= last; i++)
                min = array[i] < min ? array[i] : min;
            return min;
        }

        if (array[first] <= array[mid])
            first = mid;
        else
            last = mid;

        mid = (first + last) / 2;
    }
    return array[first];
}
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