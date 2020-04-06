#include <iostream>

#include <iostream>

// array length:n find repeated number, all number:0~n-1 P39
bool duplicate(int number[], int length, int *dupli)
{
    if (number == nullptr || length == 0)
    {
        std::cout << "error!!" << std::endl;
        return false;
    }
    for (int i = 0; i < length; ++i)
    {
        if (number[i] < 0 || number[i] > length - 1)
        {
            return false;
        }
    }
    for (int i = 0; i < length; ++i)
    {
        // std::cout << "current index: " << i << std::endl;
        while (number[i] != i)
        {
            if (number[i] == number[number[i]])
            {
                *dupli = number[i];
                return true;
            }
            int temp = number[i];
            number[i] = number[temp];
            number[temp] = temp;
        }
    }
    return false;
}

int main()
{
    int a[] = {1, 3, 1, 0, 2, 5, 4};
    // int a[7] = {};
    int a_length = sizeof(a) / sizeof(a[0]);
    int *d = new int[1];
    bool du = false;
    du = duplicate(a, a_length, d);
    std::cout << "d: " << *d << std::endl;
    std::cout << "bool value: " << du << std::endl;
    return 0;
}
