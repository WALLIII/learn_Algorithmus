#include <iostream>
#include<unordered_map>
// array length:n find repeated number, all number:0~n-1 P39
bool duplicate(int number[], int length, int *dupli)
{
    if (number == nullptr || length == 0)
    {
        return false;
    }
    for (int i = 0; i < length; ++i)
    {
        if (number[i] < 0 || number[i] > length - 1)
        {
            return false;
        }
    }
    for (int i = 0; i < length; ++i)
    {
        while (number[i] != i)
        {
            if (number[i] == number[number[i]])
            {
                *dupli = number[i];
                return true;
            }
            int temp = number[i];
            number[i] = number[temp];
            number[temp] = temp;
        }
    }
    return false;
}
// hash table
// bool duplicate(int number[], int length, int *dupli)
// {
//     if (number == nullptr || length == 0)
//     {
//         return false;
//     }
//     std::unordered_map<int, int> hash;
//     for (int i = 0; i < length; ++i)
//     {

//         hash[number[i]]++;
//     }
//     for (int i = 0; i < length; ++i)
//     {
//         if (hash[number[i]] > 1)
//         {
//             *dupli = number[i];
//             return true;
//         }
//     }
//     *dupli = -1;
//     return false;
// }
// 动态数组的做hash table
// bool douplicate(int numbers[], int length, int *value)
// {
//     if (numbers == nullptr || length <= 0)
//     {
//         return false;
//     }
//     int *assistantArray = (int *)malloc(length * sizeof(int));
//     for (int i = 0; i < length; ++i)
//     {
//         if (assistantArray[numbers[i]] == numbers[i])
//         {
//             std::cout << "repeated number is:" << numbers[i] << std::endl;
//             *value = numbers[i];
//             return true;
//         }
//         assistantArray[numbers[i]] = numbers[i];
//     }
//     free(assistantArray);
//     return false;
// }
int main()
{
    int a[] = {1, 3, 1, 0, 2, 5, 4};
    // int a[7] = {};
    int a_length = sizeof(a) / sizeof(a[0]);
    int *d = new int[1];
    bool du = false;
    du = duplicate(a, a_length, d);
    std::cout << "d: " << *d << std::endl;
    std::cout << "bool value: " << du << std::endl;
    return 0;
}
