#include <iostream>
#include <vector>
// 冒泡排序
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
// 快速排序
int Partition(std::vector<int> &arr, int l, int r){
    int tmp=arr[l];
    while(l<r){
        while(l<r && arr[r]>=tmp)
            --r;
        std::swap(arr[l], arr[r]);
        while(l<r && arr[l]<tmp)
            ++l;
        std::swap(arr[l], arr[r]);
    }
    return l;
}

int randomPartition(std::vector<int> &arr, int l, int r){
    int ran=rand()%(r-l+1)+l;
    std::swap(arr[ran], arr[l]);
    return Partition(arr, l, r);
}

void quickSortPart(std::vector<int> &arr, int l, int r){
    if(l>=r)
        return;
    int index=randomPartition(arr, l, r);
    quickSortPart(arr, l, index-1);
    quickSortPart(arr, index+1, r);
}

void quickSort(std::vector<int> &arr){
    if(arr.size()<=0)
        return;
    return quickSortPart(arr, 0, arr.size()-1);
}
// 插入排序
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
//  并归排序
void mergeSortCore(std::vector<int> &array, int *&copy, int start, int end)
{
    if (start == end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSortCore(array, copy, start, mid);
    mergeSortCore(array, copy, mid + 1, end);
    int p1 = mid, p2 = end, index = end;
    while (p1 >= start && p2 >= mid + 1)
    {
        if (array[p1] > array[p2])
        {
            copy[index--] = array[p1--];
        }
        else
        {
            copy[index--] = array[p2--];
        }
    }
    for (; p1 >= start; --p1)
    {
        copy[index--] = array[p1];
    }
    for (; p2 >= mid + 1; --p2)
    {
        copy[index--] = array[p2];
    }
    for (int i = start; i <= end; ++i)
    {
        array[i] = copy[i];
    }
}
void mergeSort(std::vector<int> &array)
{
    if (array.size() <= 1)
        return;
    int *copy = new int[array.size()];
    for (int i = 0; i < array.size(); ++i)
        copy[i] = 0;
    mergeSortCore(array, copy, 0, array.size() - 1);
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