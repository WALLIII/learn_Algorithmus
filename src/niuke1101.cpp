#include <iostream>
#include <exception>
void SortAge(int ages[], int length)
{
    if (ages == nullptr || length <= 0)
    {
        return;
    }
    int const oldestAge = 99;
    int countAge[oldestAge + 1];
    for (int i = 0; i <= oldestAge; ++i)
    {
        countAge[i] = 0;
    }
    for (int i = 0; i < length; ++i)
    {
        int age = ages[i];
        if (age < 0 || age > 99)
        {
            return;
        }
        ++countAge[age];
    }
    for (int i = 0; i <= oldestAge; ++i)
    {
        if (countAge[i] > 0)
        {
            std::cout << i << "  ";
        }
    }
    std::cout << std::endl;
    int index = 0;
    for (int i = 0; i <= oldestAge; ++i)
    {
        for (int j = 0; j < countAge[i]; ++j)
        {
            ages[index] = i;
            ++index;
        }
    }
}

int main()
{
    int ages[] = {30, 40, 25, 60, 40, 1, 99};
    SortAge(ages, 6);
    for (int i = 0; i < 6; ++i)
    {
        std::cout << ages[i] << "  ";
    }
    std::cout << std::endl;
    return 0;
}