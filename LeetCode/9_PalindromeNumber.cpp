#include <iostream>
#include <limits>
bool isPalindrome(int x)
{
    int reverse = 0;
    int iniX = x;
    if (x < 0)
        return false;
    else if (x == 0)
        return true;
    while (x != 0)
    {
        // if(reverse>2147447412/10){
        if(reverse>INT_MAX/10){
            // std::cout<<"1111"<<std::endl;
            return false;
        } 
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }
    if (iniX == reverse)
        return true;
    else
        return false;
}

int main()
{
    if (isPalindrome(2147447412))
        std::cout << "is palidrome" << std::endl;
    else
        std::cout << "is not palidrome" << std::endl;
    return 0;
}