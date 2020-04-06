#include <iostream>
#include <vector>

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

std::vector<int> GetLeastNumbers_Solution(std::vector<int> input, int k)
{
    std::vector<int> res;
    if (input.size() <= 0 || k > input.size() || k <= 0)
    {
        return res;
    }

    int len = input.size();
    int first = 0, last = len - 1;
    int tmpIndex = Partition(input, first, last);

    while (tmpIndex != k)
    {
        if (tmpIndex < k)
        {
            first = tmpIndex + 1;
            tmpIndex = Partition(input, first, last);
        }
        if (tmpIndex > k)
        {
            last = tmpIndex - 1;
            tmpIndex = Partition(input, first, last);
        }
    }
    for (int i = 0; i < tmpIndex; ++i)
    {
        res.push_back(input[i]);
    }
    return res;
}

int main()
{
    std::vector<int> input = {4, 5, 1, 6, 2, 7, 3, 8};
    std::vector<int> res;
    res = GetLeastNumbers_Solution(input, 10);
    for (auto a : res)
    {
        std::cout << a << "  ";
    }
    std::cout << std::endl;
    std::cout << "input:  " << std::endl;
    for (auto a : input)
    {
        std::cout << a << "  ";
    }
    std::cout << std::endl;
    return 0;
}
