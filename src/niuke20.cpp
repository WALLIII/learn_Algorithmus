#include <string>
#include <iostream>

bool isNumeric(const char *str)
{
    if(str==nullptr)
        return false;
    bool sign = false, decimal = false, hasE = false;
    for (int i = 0; i < std::strlen(str); i++)
    {
        // correction of e
        if (str[i] == 'e' || str[i] == 'E')
        {
            if (i == strlen(str) - 1)
                return false; // e must follow with number
            if (hasE)
                return false; // cannot exist more than one e
            hasE = true;
        }
        else if (str[i] == '+' || str[i] == '-')
        {

            if (sign && str[i - 1] != 'e' && str[i - 1] != 'E')
                return false;

            if (!sign && i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E')
                return false;
            sign = true;
        }
        else if (str[i] == '.')
        {

            if (hasE || decimal)
                return false;
            decimal = true;
        }
        else if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

void test(const char* str)
{
    if(isNumeric(str))
        std::cout<<str<<"---passed!!"<<std::endl;
    else
        std::cout<<str<<"---failed!!"<<std::endl;
}
int main()
{
    test("5e-1");
    test("1.233445");
    test("+67e-9");
    test(".123");
    test("0");
    test("123.");


    test("e-8");
    test("1e-8-78");
    test("2e-5.6");
    test("5e0e");
    

    return 0;
}