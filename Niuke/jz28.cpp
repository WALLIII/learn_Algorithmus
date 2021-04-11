#include <vector>
#include <iostream>
#include <unordered_map>

// int MoreThanHalfNum_Solution(std::vector<int> numbers)
// {
//     std::unordered_map<int, int> map(0);
//     int size = numbers.size();
//     for (int i = 0; i < size; ++i)
//     {
//         map[numbers[i]]++;
//         if (map[numbers[i]] > size / 2)
//             return numbers[i];
//     }
//     return 0;
// }

int Partition(std::vector<int> &arr, int first, int last)
{
    int tmp = arr[last];
    while (first < last)
    {
        while (first < last && arr[first] < tmp)
            first++;
        std::swap(arr[first], arr[last]);
        while (first < last && arr[last] >= tmp)
            last--;
        std::swap(arr[first], arr[last]);
    }
    return last;
}


bool check(std::vector<int> arr, int result)
{
    int count = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == result)
            count++;
        if (count > arr.size() / 2)
            return true;
    }
    return false;
}

int MoreThanHalfNum_Solution(std::vector<int> numbers)
{
    int size = numbers.size();
    if (size <= 0)
        return 0;
    int middle = size / 2;
    int start = 0, end = size - 1;
    int index = Partition(numbers, start, end);
    while (index != middle)
    {
        if (index < middle)
        {
            start = index + 1;
            index = Partition(numbers, start, end);
        }
        if (index > middle)
        {
            end = index - 1;
            index = Partition(numbers, start, end);
        }
    }
    if (check(numbers, numbers[index]))
        return numbers[index];
    else
        return 0;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int res = MoreThanHalfNum_Solution(arr);
    std::cout << "Result:  " << res << std::endl;
    // std::cout<<(9>>1)<<std::endl;
    return 0;
}