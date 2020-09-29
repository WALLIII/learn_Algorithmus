#include <iostream>
#include <vector>


int FindFirst(std::vector<int> data, int k, int start, int end)
{
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    if (data[mid] == k)
    {
        if (start == mid || (data[mid-1] != k))
            return mid;
        else
            end = mid - 1;
    }
    else if (data[mid] > k)
        end = mid - 1;
    else
        start = mid + 1;
    return FindFirst(data, k, start, end);
}

int FindLast(std::vector<int> data, int k, int start, int end)
{
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    if (data[mid] == k)
    {
        if (end == mid|| (data[mid+1] != k))
            return mid;
        else
            start = mid + 1;
    }
    else if (data[mid] > k)
        end = mid - 1;
    else
        start = mid + 1;
    return FindLast(data, k, start, end);
}

int GetNumberOfK(std::vector<int> data, int k)
{
    if (data.size() <= 0)
        return -1;
    int first = 0, last = data.size() - 1;
    first = FindFirst(data, k, 0, data.size() - 1);
    last = FindLast(data, k, 0, data.size() - 1);
    if (first != -1 && last != -1)
        return last - first + 1;
    else
        return 0;
}
int main()
{
    std::vector<int> arr = {1, 3, 3, 3, 3, 4, 5};
    std::cout << GetNumberOfK(arr, 2) << std::endl;
    return 0;
}