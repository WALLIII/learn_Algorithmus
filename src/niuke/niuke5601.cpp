#include <vector>
#include <iostream>

bool IsBit(int num, int index)
{
    num = num >> index;
    return (num & 1);
}

void FindNumsAppearOnce(std::vector<int> data, int *num1, int *num2)
{
    if (data.size() < 2)
        return;
    int size = data.size();
    int temp = data[0];
    for (int i = 1; i < size; i++)
    {
        temp = temp ^ data[i];
    }
    std::cout << std::endl;
    if (temp == 0)
        return;
    int index = 0;
    while ((temp & 1) == 0)
    {
        temp = temp >> 1;
        ++index;
    }
    *num1 = *num2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (IsBit(data[i], index))
        {
            *num1 ^= data[i];
        }
        else
        {
            *num2 ^= data[i];
        }
    }
}
void FindOneNumsAppearOnce(std::vector<int> data, int *num1)
{
    if (data.size() < 2)
        return;
    int size = data.size();
    int temp = data[0];
    for (int i = 1; i < size; i++)
    {
        temp = temp ^ data[i];
        std::cout<<temp<<"  ";
    }

    std::cout << std::endl;
    if (temp == 0)
        return;
    int index = 0;
    while ((temp & 1) == 0)
    {
        temp = temp >> 1;
        ++index;
    }
    *num1 = temp;
}
int main()
{
    std::vector<int> data = {2, 4, 4, 3, 3, 2, 5};
    int a = 0, b = 0;
    int *num1 = &a, *num2 = &b;
   
    FindNumsAppearOnce(data, num1, num2);
    std::cout<<"num1: "<<*num1<<"  num2: "<<*num2<<std::endl;
    FindOneNumsAppearOnce(data, num1);
    std::cout<<"num1: "<<*num1<<std::endl;
    // std::cout << (2 ^ 4);
}