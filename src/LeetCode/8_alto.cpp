#include <iostream>
#include <limits>
#include <string>

int myAtoi(std::string str)
{
    int len = str.size();
    if (len <= 0)
        return 0;
    bool isMinus = false;
    int res = 0;
    int i = 0;
    while (str[i] == ' ' && i < len)
    {
        ++i;
    }
    if (i >= len)
        return 0;
    if (str[i] > '9' || str[i] < '0')
    {
        if (str[i] != '-' && str[i] != '+')
            return 0;
    }
    if (str[i] == '-' && isMinus == false)
    {
        isMinus = true;
        ++i;
    }
    else if (str[i] == '+')
    {
        ++i;
    }

    if (str[i] >= '0' && str[i] <= '9')
    {
        while (str[i] >= '0' && str[i] <= '9' && i < len)
        {
            int u=int(str[i]) - '0';
            if (res > (INT_MAX-u)/10){
                return isMinus?INT_MIN:INT_MAX;
          
            }
                
            res *= 10;
            res += u;
            ++i;
        }
    }
    else
        return 0;

    if (isMinus)
        res = -res;
    return res;
}
// int myAtoi(std::string str)
// {
//     const int slen = str.size();
//     if (slen == 0)
//         return 0; // 空字符串
//     int i = 0;    // str的下标
//     while (i < slen && str[i] == ' ')
//         ++i; // 跳过空格
//     if (i >= slen)
//         return 0;
//     // read sign
//     char c = str[i];
//     bool minus = false;
//     if (c == '-')
//     {
//         minus = true;
//         ++i;
//     }
//     else if (c == '+')
//         ++i;
//     int v = 0;
//     bool valid = false;
//     while (i < slen && str[i] >= '0' && str[i] <= '9')
//     {
//         valid = true;
//         int u = str[i] - '0';
//         std::cout << "u:  " << u << std::endl;
//         // v * 10 - u >= INT32_MIN
//         // v * 10 >= INT32_MIN + u
//         if (v < INT32_MIN / 10 || v * 10 < INT32_MIN + u)
//             return minus ? INT32_MIN : INT32_MAX;
//         std::cout << "v:  " << v << std::endl;
//         v = v * 10 - u;
//         ++i;
//     }
//     if (!valid)
//         return 0;
//     if (minus)
//         return v;
//     if (v == INT32_MIN)
//         return INT32_MAX;
//     return -v;
// }
int main()
{
    std::string str = "-9";
    std::cout << myAtoi(str) << std::endl;
    return 0;
}