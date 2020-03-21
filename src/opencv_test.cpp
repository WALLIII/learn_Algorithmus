#include <iostream>
#include<time.h>

long long fibonacci_recursively(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fibonacci_recursively(n - 1) + fibonacci_recursively(n - 2);
}

long long fibonacci(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    long long n1 = 0, n2 = 1;
    long long result = 0;
    for (int i = 2; i <= n; ++i)
    {
        result = n1 + n2;
        n1 = n2;
        n2 = result;
    }
    return result;
}

int main()
{
    time_t start_re, end_re;
    time_t start_lo, end_lo;
    long long n1, n2;
    start_re = clock();
    n1 = fibonacci_recursively(390);
    end_re = clock();
    std::cout << "recurrence res: " << n1 << "  recurrence time: " << (end_re - start_re) << std::endl;

    start_lo = clock();
    n2 = fibonacci(390);
    end_lo = clock();
    std::cout << "loop res: " << n2 << "  loop time: " << (end_lo - start_lo) << std::endl;
    std::cout<<"CLOCKS_PER_SEC"<<CLOCKS_PER_SEC<<std::endl;
}