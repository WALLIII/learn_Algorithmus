#include <iostream>
#include <cmath>
long long int cutRope_dp(int number)
{
    if (number < 2)
        return 0;
    if (number == 2)
        return 1;
    if (number == 3)
        return 2;
    long long int *products = new long long int[number + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;
    for (int i = 4; i <= number; ++i)
    {
        long long int max = 0;
        for (int j = 1; j <= i / 2; ++j)
        {
            long long int product = products[j] * products[i - j];
            if (max < product)
            {
                max = product;
            }
            products[i] = max;
        }
    }
    // std::cout<<" products[number]"<<products[60]<<std::endl;
    long long int result = products[number];
    delete[] products;
    return result;
}
long long int cutRope(int number)
{
    if (number < 2)
        return 0;
    if (number == 2)
        return 1;
    if (number == 3)
        return 2;
    int Length3 = number / 3;
    if (number - Length3 * 3 == 1)
    {
        Length3 -= 1;
    }
    int Length2 = (number - Length3 * 3) / 2;
    // std::cout << "Length3:  " << Length3 << "  Length2:  " << Length2 << std::endl;
    return (pow(3, Length3)) * (pow(2, Length2));
}
int main()
{
    // { 2066242608--->60
    for(int number=4; number<=60;++number)
    {
        std::cout << "number: "  << number 
                << " product_dp: " << cutRope_dp(number)
                << " product: " << cutRope(number) << std::endl;
    }
    return 0;
}