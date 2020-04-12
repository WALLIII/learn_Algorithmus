
#include <vector>
#include <iostream>
#include <bitset>

int FindOneNumsAppearOnce(std::vector<int> data, int *num1)
{
    int ass[32] = {0};
    for (int i = 0; i < data.size(); ++i)
    {
        int bitMask = 1;
        for (int j = 31; j >= 0; --j)
        {
            int bit=data[i] & bitMask;
            if (bit!= 0)
                ass[j] += 1;
            bitMask = bitMask << 1;
        }
    }
    // *num1=0;
    int result = 0;
    for (int i = 0; i < 32; ++i)
    {
        std::cout<<"result before<<1:  "<<std::bitset<32>(result)<<std::endl;
        result = result << 1;
        std::cout<<"result after <<1:  "<<std::bitset<32>(result)<<std::endl;

        result += ass[i] % 3;
    }
    return result;
}
int main()
{
    std::vector<int> data = {1, 1, 1, 3, 3, 3, 5, 8, 8, 8};
    int a = 0, b = 0;
    int *num1 = &a, *num2 = &b;

    // FindOneNumsAppearOnce(data, num1);
    int res=FindOneNumsAppearOnce(data, num1);
    std::cout << "res: " << res << std::endl;
    // std::cout << (2 ^ 4);
}