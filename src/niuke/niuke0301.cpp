#include <iostream>
#include <cstdlib>
// methode1: an assistant array is needed
bool douplicate(int numbers[], int length, int *value)
{
    if (numbers == nullptr || length <= 0)
    {
        return false;
    }
    int *assistantArray = (int *)malloc(length * sizeof(int));
    for (int i = 0; i < length; ++i)
    {
        if (assistantArray[numbers[i]] == numbers[i])
        {
            std::cout << "repeated number is:" << numbers[i] << std::endl;
            *value = numbers[i];
            return true;
        }
        assistantArray[numbers[i]] = numbers[i];
    }
    free(assistantArray);
    return false;
}
// methode2: Bisection method
int getDuplication(const int *numbers, int length)
{
    if (numbers == nullptr || length < 0)
    {
        return -1;
    }
    int start = 1;
    int end = length - 1;
    while (end >= start)
    {
        // ????
        
    }
}
int main()
{
    int a[] = {2, 3, 5, 4, 3, 2, 6, 7};
    int *value = nullptr;
    int a_length = sizeof(a) / sizeof(a[0]);
    bool is_douplicates = false;
    is_douplicates = douplicate(a, a_length, value);
    std::cout << "repested result is:" << value << std::endl;
    return 0;
}