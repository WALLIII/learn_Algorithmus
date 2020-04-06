#include <iostream>

int NumberOf1Between1AndN_Solution(int n)
{
    int count = 0;
    long long i = 1;
    for (i = 1; i <= n; i *= 10)
    {
        int a = n / i, b = n % i;
        std::cout << "a: "<<a << std::endl;
        std::cout << "b: "<<b << std::endl;
        std::cout<<"(a + 8) / 10 * i: "<<(a + 8) / 10 * i<<std::endl;
        std::cout<<"(a ) / 10 : "<<(a ) / 10<<std::endl;
        std::cout<<"(a % 10 == 1) * (b + 1): "<<(a % 10 == 1) * (b + 1)<<std::endl;
        count = count + (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
    }
    return count;
}
int main()
{
    std::cout << NumberOf1Between1AndN_Solution(31201) << std::endl;
    // std::cout << (31241+ 8) / 10 << std::endl;

}