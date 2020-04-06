#include <string>
#include <iostream>
#include <cstring>

void replaceSpace(char *str, int length)
{
    if (str == nullptr || length <= 0)
    {
        return;
    }
    int oldLength = 0, newLength = 0;
    int numBlack = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            ++numBlack;
        }
        ++oldLength;
        ++i;
    }
    newLength = oldLength + 2 * numBlack;
    std::cout << "newLength:" << newLength << std::endl;
    std::cout << "oldLength:" << oldLength << std::endl;
    std::cout << "numBlack:" << numBlack << std::endl;
    if (newLength > length)
        return;
    int indexOriginal = oldLength;
    int indexNew = newLength;
    while (indexOriginal >= 0 && indexNew > indexOriginal)
    {
        if (str[indexOriginal] == ' ')
        {
            str[indexNew--] = '0';
            str[indexNew--] = '2';
            str[indexNew--] = '%';
        }
        else
        {
            str[indexNew--] = str[indexOriginal];
        }
        --indexOriginal;
    }
}

int main()
{
    char str[] = "";
    int length = 100;
    replaceSpace(str, length);
    std::cout << str << std::endl;
    return 0;
}