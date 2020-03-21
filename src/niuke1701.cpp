#include <iostream>
bool InvalidInput = false;
double PowerWithUnsighedExponent(double base, unsigned int exponent)
{
    if (exponent == 1)
    {
        return base;
    }
    if (exponent == 0)
    {
        return 1.0;
    }
    double result = PowerWithUnsighedExponent(base, exponent >> 1);
    result *= result;
    if ((exponent & 0x1) == 1)
    {
        result *= base;
    }
    return result;
}
double Power(double base, int exponent)
{
    InvalidInput = false;
    if (exponent == 0 && base != 0)
    {
        return 1.0;
    }
    if (exponent <= 0 && base == 0.0)
    {
        InvalidInput = true;

        return 0.0;
    }
    if (exponent > 0 && base == 0.0)
    {
        return 0.0;
    }
    unsigned int absExponent = (unsigned int)(exponent);
    if (exponent < 0)
    {
        absExponent = (unsigned int)(-exponent);
    }
    double result = 1.0;
    result = PowerWithUnsighedExponent(base, absExponent);
    if (exponent < 0)
    {
        result = 1.0 / result;
    }
    return result;
}

int main()
{
    double result = Power(5, -1);
    if (InvalidInput == true)
    {
        std::cout << "ERROR!!" << std::endl;
    }
    else
    {
        std::cout << result << std::endl;
    }
    return 0;
}