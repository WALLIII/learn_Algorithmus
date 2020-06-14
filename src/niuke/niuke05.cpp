#include <string>
#include <iostream>

void replaceSpace(char *str, int length)
{
    if (str == nullptr || length == 0)
        return;
    int oldLength = 0, newLength = 0, i = 0;
    while (str[i] != '\0')
    {
        oldLength++;
        newLength++;
        if (str[i] == ' ')
            newLength += 2;
        ++i;
    }
    std::cout << "old:  " << oldLength << "  new:  " << newLength << std::endl;
    if (newLength > length)
        return;
    int p1 = oldLength, p2 = newLength;
    while (p1 >= 0 && p2 > p1)
    {
        if (str[p1] != ' ')
        {
            str[p2--] = str[p1--];
        }
        else if (str[p1] == ' ')
        {
            str[p2--] = '0';
            str[p2--] = '2';
            str[p2--] = '%';
        }
    }
}

int main()
{
    char str[100] = "we are happy.";
    replaceSpace(str, 100);
    std::cout << "res:  " << str << std::endl;
}