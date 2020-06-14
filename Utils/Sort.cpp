#include <iostream>
#include <vector>

void BubbleSort(std::vector<int> &arr)
{
    int len = arr.size();
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int Partition(std::vector<int> &arr, int first, int last);
void quickSortPart(std::vector<int> &arr, int first, int last);
void quickSort(std::vector<int> &arr)
{
    if (arr.size() < 1)
        return;
    quickSortPart(arr, 0, arr.size() - 1);
}
void quickSortPart(std::vector<int> &arr, int first, int last)
{
    if (first >= last)
    {
        return;
    }
    int midIndex = Partition(arr, first, last);
    quickSortPart(arr, first, midIndex - 1);
    quickSortPart(arr, midIndex + 1, last);
}

int Partition(std::vector<int> &arr, int first, int last)
{
    int tmp = arr[last];
    while (first < last)
    {
        while (first < last && arr[first] <= tmp)
            first++;
        std::swap(arr[first], arr[last]);
        while (first < last && arr[last] >= tmp)
            last--;
        std::swap(arr[first], arr[last]);
    }
    return last;
}

void inlineSort(std::vector<int> &array)
{
    if (array.size() == 0)
        return;
    for (int i = 0; i < array.size(); ++i)
    {
        if (array[i] < array[i - 1])
        {
            int tmp = array[i];
            int j = i - 1;
            while (j >= 0 && tmp < array[j])
            {
                array[j + 1] = array[j];
                --j;
            }
            array[j + 1] = tmp;
        }
    }
}

int main()
{
    std::vector<int> arr = {8, 4, 7, 5, 1, 3};
    quickSort(arr);
    for (auto a : arr)
    {
        std::cout << a << "  ";
    }
    std::cout << std::endl;

    return 0;
}