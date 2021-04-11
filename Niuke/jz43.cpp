#include <string>
#include <iostream>
void ReverseWord(std::string &str, int s, int e)
{
    while (s < e)
    {
        std::swap(str[s], str[e]);
        s++;
        e--;
    }
}

std::string LeftRotateString(std::string str, int n)
{
    if (str.size() <= 1)
        return str;
    ReverseWord(str, 0, str.size()-1);
    ReverseWord(str, str.size()-n, str.size()-1);
    ReverseWord(str, 0, str.size()-1-n);

    return str;
}

int main()
{
    std::string str = "abcXYZdef";
    std::string str2;
    str2 = LeftRotateString(str, 3);
    std::cout << str2 << std::endl;
    return 0;
}