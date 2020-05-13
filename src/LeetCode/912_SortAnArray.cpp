#include <vector>
#include <iostream>

// quick sort
int Partition(std::vector<int> &arr, int first, int last)
{
    int i = rand() % (last - first + 1) + first; // 随机选一个作为我们的主元
    //设置哨兵为每个子数组的最后一个元素   
    std::swap(arr[last], arr[i]);

    int tmp = arr[last];
    while (first < last)
    {
        // 从头开始扫描，找到第一个比哨兵大的元素，跳出循环，并交换这两个元素。
        // 交换元素的值并不会影响first和last指向的位置。
        while (first < last && arr[first] <= tmp)
            first++;
        // arr[last]即哨兵,现在first的位置指向哨兵
        std::swap(arr[first], arr[last]);
        // 从尾部开始扫描，找到第一个比哨兵小的元素，跳出循环，交换这两个元素。
        while(first<last&&arr[last]>=tmp)
            last--;
        std::swap(arr[first], arr[last]);
    }
    return last;
}

void quickSortPart(std::vector<int> &arr, int first, int last)
{
    if (first >= last)
    {
        return;
    }
    // 求出哨兵的序号，同时保证哨兵的左边都比哨兵小，右边的都比哨兵大，但是不一定有序。
    // 将左边右边分别送入quickSortPart，递归求解。递归出口是子数组只含有一个元素。
    int pivotIndex = Partition(arr, first, last);
    quickSortPart(arr, first, pivotIndex - 1);
    quickSortPart(arr, pivotIndex + 1, last);
}

void quickSortArray(std::vector<int> &nums)
{
    if (nums.size() <= 1)
        return;
    quickSortPart(nums, 0, nums.size() - 1);
}

// heap sort
void HeapAdjust(std::vector<int> &arr, int first, int end)
{
    int father = first;
    int son = father * 2 + 1;
    while (son < end)
    {
        // 比较左右儿子，如果右儿子大就选右儿子和父节点交换，选到右儿子就是要做儿子+1
        if (son + 1 < end && arr[son] < arr[son + 1]){
            ++son;
        }
        if (arr[father] > arr[son])
            break; //如果父节点大于子节点则表示调整完毕
        else
        {
            std::swap(arr[father], arr[son]); //不然就交换父节点和子节点的元素
            //父节点调整完之后，可能新换下来的父节点要比左右儿子大，所以要继续调整。
            // e.g. [-4,0,7,4,9,-5,-1,0,-7,-1]
            father = son;                     
            son = 2 * father + 1;
        }
    }
}

void heapSortArray(std::vector<int> &nums)
{
    int i;
    int len = nums.size();
    for (i = len / 2 - 1; i >= 0; --i)
    {
        //初始化堆，从最后一个父节点开始
        HeapAdjust(nums, i, len); 
    }
    for (i = len - 1; i > 0; --i)
    {
        //从堆中的取出最大的元素再调整堆
        std::swap(nums[0], nums[i]); 
         //调整成堆
        HeapAdjust(nums, 0, i);    
    }
}

// merge sort
void mergeSort(std::vector<int> &nums, std::vector<int> &tmp, int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    mergeSort(nums, tmp, l, mid);
    mergeSort(nums, tmp, mid + 1, r);
    int i = l, j = mid + 1;
    int cnt = 0;
    while (i <= mid && j <= r)
    {
        if (nums[i] < nums[j])
        {
            tmp[cnt++] = nums[i++];
        }
        else
        {
            tmp[cnt++] = nums[j++];
        }
    }
    while (i <= mid)
        tmp[cnt++] = nums[i++];
    while (j <= r)
        tmp[cnt++] = nums[j++];
    for (int i = 0; i < r - l + 1; ++i)
        nums[i + l] = tmp[i];
}

std::vector<int> sortArray(std::vector<int> &nums)
{
    std::vector<int> tmp;
    tmp.resize((int)nums.size(), 0);
    mergeSort(nums, tmp, 0, (int)nums.size() - 1);
    return nums;
}


int main()
{
    std::vector<int> arr = {5, 4, 7, 4};
    quickSortArray(arr);
    for (auto a : arr)
        std::cout << a << "  ";
    std::cout << std::endl;
    return 0;
}