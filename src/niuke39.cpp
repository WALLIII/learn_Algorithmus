#include <vector>
#include <iostream>

int Partition(std::vector<int> &arr, int first, int last)
{
    int tmp = arr[first];
    while (first < last)
    {
        while (first < last && arr[last] >= tmp)
            last--;
        std::swap(arr[first], arr[last]);
        while (first < last && arr[first] <= tmp)
            first++;
        std::swap(arr[first], arr[last]);
    }
    return first;
}
bool check(std::vector<int> arr, int result)
{
    int len = arr.size();
    int count = 0;
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] == result)
        {
            count++;
        }
    }
    if (count >=   len / 2 + 1)
        return true;
    else
        return false;
}

int MoreThanHalfNum_Solution(std::vector<int> numbers)
{
    if (numbers.size() <= 0)
    {
        return 0;
    }
    int len = numbers.size();
    int middle = len / 2;
    int first = 0, last = len - 1;
    int tmpIndex = Partition(numbers, first, last);

    while (tmpIndex != middle)
    {
        if (tmpIndex < middle)
        {
            first = tmpIndex + 1;
            tmpIndex = Partition(numbers, first, last);
        }
        if (tmpIndex > middle)
        {
            last = tmpIndex - 1;
            tmpIndex = Partition(numbers, first, last);
        }
    }
    int tmpResult = numbers[tmpIndex];

    if (!check(numbers, tmpResult))
    {
        return 0;
    }
    return tmpResult;
}

int main()
{
    std::vector<int> arr = {1,2,3,2,2,2,5,4,2};
    int res = MoreThanHalfNum_Solution(arr);
    std::cout << "Result:  " << res << std::endl;
    // std::cout<<(9>>1)<<std::endl;
    return 0;
}