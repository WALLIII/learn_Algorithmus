#include <iostream>
#include<math.h>

int jumpFloor(int number)
{
    if (number <= 1)
    {
        return number;
    }
    else
    {
        int f_1 = 0, f_2 = 1, f_n = 0;
        for (int i = 1; i <= number; ++i)
        {
            f_n = f_1 + f_2;
            f_1 = f_2;
            f_2 = f_n;
        }
        return f_n;
    }
}

int jumpFloor2(int number)
{
    if(number==0)
        return 0;
    return pow(2, number-1);
}

int main()
{
    std::cout << jumpFloor2(2) << std::endl;
    std::cout << jumpFloor2(3) << std::endl;
    std::cout << jumpFloor2(4) << std::endl;
    std::cout << jumpFloor2(5) << std::endl;
}