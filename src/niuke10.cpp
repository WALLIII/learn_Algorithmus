#include <iostream>
#include <iostream>
#include <time.h>
#include <unistd.h>
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
    clock_t start_lo, end_lo;
    long long n1, n2, n3;
    time(&start_re);
    n1 = fibonacci_recursively(50);
    // sleep(2);
    time(&end_re);
    std::cout << "recurrence res: " << n1 << "  recurrence time: " << difftime(end_re ,start_re) << std::endl;

    clock_t a, b;
    a=clock();
    n3 = fibonacci_recursively(50);
    // sleep(20);

    b=clock();
    std::cout << "recurrence res clock: " << n3 << "  recurrence time: " << (b-a) << std::endl;

    // start_lo = clock();
    // sleep(2);
    // end_lo = clock();
    // std::cout << "time1: " << (end_lo - start_lo)/CLOCKS_PER_SEC << std::endl;
    // time(&start_re);
    // sleep(2);
    // time(&end_re);
    // std::cout << "time2: " << (end_re - start_re) << std::endl;
    // std::cout << "time3: " << difftime(end_re,start_re) << std::endl;
    
    // std::cout << "loop res: " << n2 << "  loop time: " << (end_lo - start_lo) << std::endl;
    // std::cout<<"CLOCKS_PER_SEC"<<CLOCKS_PER_SEC<<std::endl;
    // std::cout<<"CLK_TCK"<<CLK_TCK<<std::endl;
    
    // time_t time_now, time_end;
    // time(&time_now);
    // sleep(2);
    // time(&time_end);
    // char tmp_gm[64];
    // char tmp_local[64];
    // strftime(tmp_gm, sizeof(tmp_gm), "%Y-%m-%d %H:%M:%S", gmtime(&time_end));
    // strftime(tmp_local, sizeof(tmp_local), "%Y-%m-%d %H:%M:%S", localtime(&time_end));

    // std::cout << difftime(time_end, time_now) << std::endl;
    // std::cout << "shifted time gt: " << tmp_gm << std::endl;
    // std::cout << "shifted time local: " << tmp_local << std::endl;

}