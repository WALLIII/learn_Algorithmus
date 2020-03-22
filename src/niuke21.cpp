#include <iostream>
#include <vector>
// out of order
void reOrderArray_OutOfOrder(std::vector<int> &array)
{
    if (array.size() == 0)
        return;
    int p1 = 0, p2 = (array.size() - 1);
    while (p1 < p2)
    {
        if ((array[p1] % 2) == false && (array[p2] % 2) == true)
        {
            int tmp = array[p1];
            array[p1] = array[p2];
            array[p2] = tmp;
            p1 += 1;
        }
        else if ((array[p1] % 2) == false && (array[p2] % 2) == false)
        {
            p2 -= 1;
        }
        else if ((array[p1] % 2) == true)
        {
            if ((array[p2] % 2) == false)
            {
                p1 += 1;
                p2 -= 1;
            }
            else
            {
                p1 += 1;
            }
        }
    }
}

void reOrderArray(std::vector<int> &array)
{
    if (array.size() == 0)
        return;

    for (int i = 0; i < array.size(); i++)
    {
        //int temp=array[i];
        if (array[i] % 2 == 1)
        {
            int temp = array[i];
            int j = i - 1;
            std::cout<<"j:  "<<j<<"array[j]"<<array[j]<<std::endl;
            while (j >= 0 && array[j] % 2 == 0)
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = temp;
        }
    }
}

// void inlineSort(std::vector<int> &array)
// {
//     if (array.size() == 0)
//         return;
//     for (int i = 1; i < array.size(); ++i)
//     {
//         if(array[i]<array[i-1]){
//             int tmp=array[i];
//             int j=i;
//             while(j>0 &&tmp<array[j-1]){
//                 array[j]=array[j-1];
//                 --j;
//             }
//             array[j]=tmp;
//         }
        
//     }
// }
void print(const std::vector<int> &array)
{
    if (array.size() == 0)
        return;
    for (auto v : array)
        std::cout << v << "   ";
    std::cout << std::endl;
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
                std::cout<<"inside while "<<std::endl;
                print(array);
            }
            std::cout<<"outside while "<<std::endl;
            array[j + 1] = tmp;
            print(array);
        }
    }
}
int main()
{
    std::vector<int> vec1 = {1,2,3,4,5};
    std::vector<int> vec2 = vec1;

    reOrderArray_OutOfOrder(vec1);
    reOrderArray(vec2);
    std::cout << "out of order result:  ";
    for (auto v : vec1)
    {
        std::cout << v << "   ";
    }
    std::cout << std::endl;
    std::cout << "in order result:  ";
    for (auto v2 : vec2)
    {
        std::cout << v2 << "   ";
    }
    std::cout << std::endl;
    return 0;
}
