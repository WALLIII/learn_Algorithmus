#include <iostream>
#include <time.h>
long long Fibonacci_re(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return Fibonacci_re(n - 1) + Fibonacci_re(n - 2);
}
long long Fibonacci_lo(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    long long res = 0, res_1=1, res_2=0;
    for (int i = 2; i <= n; ++i)
    {
        res = res_1 + res_2;
        res_2=res_1;
        res_1=res;
    }
    return res;
}

int main()
{
    long long n = 0;
    time_t start_re, end_re;
    time_t start_lo, end_lo;
    start_re = clock();
    n = Fibonacci_re(39);
    end_re = clock();
    std::cout << "recurrence res: " << n << "  recurrence time: " << (end_re - start_re) << std::endl;

    start_lo = clock();
    n = Fibonacci_re(39);
    end_lo = clock();
    std::cout << "loop res: " << n << "  loop time: " << (end_lo - start_lo) << std::endl;
    std::cout<<"CLOCKS_PER_SEC"<<CLOCKS_PER_SEC<<std::endl;
    return 0;
}