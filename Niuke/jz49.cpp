#include <string>
#include <iostream>
// leetcode上的要求，如1a23--->1
// int strToInt(std::string str)
// {
//     int i = 0;
//     while (str[i] == ' ')
//         ++i;
//     int res = 0, sign = 1, x = 0;
//     if (str[i] == '-')
//     {
//         sign = -1;
//     }
//     // 如果是类似与'-+1'这样的字符串，是非法的，不会进入下面的while直接返回0.
//     if (str[i] == '-' || str[i] == '+')
//     {
//         ++i;
//     }

//     while (str[i] >= '0' && str[i] <= '9' && i < str.size())
//     {
//         x = int(str[i] - '0');
//         if (res > INT_MAX / 10 || (x > 7 && res == INT_MAX / 10))
//         {
//             return sign == 1 ? INT_MAX : INT_MIN;
//         }

//         res = res * 10 + x;

//         ++i;
//     }
//     return res * sign;
// }
// 剑指offer49题的要求，1a23--->0
int strToInt(std::string str)
{
    int i = 0;
    while (str[i] == ' ')
        ++i;
    int res = 0, sign = 1, x = 0;
    if (str[i] == '-')
    {
        sign = -1;
    }
    // 如果是类似与'-+1'这样的字符串，是非法的，不会进入下面的while直接返回0.
    if (str[i] == '-' || str[i] == '+')
    {
        ++i;
    }

    while (i<str.size())
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            x = int(str[i] - '0');
            if (res > INT_MAX / 10 || (x > 7 && res == INT_MAX / 10))
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            res = res * 10 + x;
        }
        else
        {
            return 0;
        }
        ++i;
    }
    return res * sign;
}

int main()
{
    std::cout << strToInt("123")<<std::endl;
    std::cout << strToInt("1s23")<<std::endl;
}