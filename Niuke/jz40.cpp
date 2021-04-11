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
        // 第一组：第index位是1的数字，如果找到的话就一个个异或
        if (IsBit(data[i], index))
        {
            *num1 ^= data[i];
        }
        // 第二组：第index位是0的数字，如果找到的话就一个个异或
        else
        {
            *num2 ^= data[i];
        }
    }
}
// 第二个题目，除一个数字只出现一次外其他数字出现三次

void FindOneNumsAppearOnce(std::vector<int> data, int *num1)
{
    int result=0;
    if(data.size()<=0)
        return;
    for(int i=0;i<32;++i){
        int sum=0;
        for(int j=0;j<data.size();++j){
            sum+=((data[j]>>i)&1);
        }
        if(sum%3==1){
            result=result | (1<<i);
        }
    }
    *num1=result;
}

int main()
{
    std::vector<int> data = {2, 4, 4, 3, 3, 2, 5};
    std::vector<int> data2 = {4, 5, 6, 4, 5, 6, 7};
    int a = 0, b = 0;
    int *num1 = &a, *num2 = &b;

    FindNumsAppearOnce(data, num1, num2);
    std::cout << "num1: " << *num1 << "  num2: " << *num2 << std::endl;
    FindOneNumsAppearOnce(data2, num1);
    std::cout << "num1: " << *num1 << std::endl;
    // std::cout << (2 ^ 4);
}