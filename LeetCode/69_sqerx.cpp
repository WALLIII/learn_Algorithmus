#include <iostream>

int mySqrt2(int x)
{
    if (x < 2)
        return x;
    int left = 1, right = x / 2;
    while (left < right)
    {
        int mid = (right + left) / 2;
        if (mid > (x / mid))
            right = mid - 1;
        else
            left = mid;
    }
    return left;
}
int mySqrt(int x)
{
    if (x < 2)
        return x;
    int left = 1, right = x / 2;
    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (mid > (x / mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left - 1;
}

int main()
{
    int res = mySqrt(8);
    std::cout << res << std::endl;
}