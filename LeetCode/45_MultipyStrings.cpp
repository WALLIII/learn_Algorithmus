#include <string>
#include <iostream>
std::string multiply(std::string num1, std::string num2)
{
    int n1 = num1.size(), n2 = num2.size();
    std::string ans(n1 + n2, '0');
    for (int i = n1 - 1; i >= 0; --i)
    {
        for (int j = n2 - 1; j >= 0; --j)
        {
            int tmp = (ans[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');
            ans[i + j + 1] = tmp % 10 + '0';
            ans[i + j] += tmp / 10;
        }
    }

    for (int i = 0; i < n1 + n2; ++i)
    {
        if (ans[i] != '0')
            return ans.substr(i, n1 + n2 - i);
    }
    return "0";
    
}

int main()
{
    std::string num1 = "1", num2 = "5";
    std::cout << multiply(num1, num2) << std::endl;
    return 0;
}