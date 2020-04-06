#include <iostream>
#include <string>
#include <cstring>
#include <vector>

void insertArray(std::vector<int> &vec1, std::vector<int> &vec2)
{
    if (vec1.empty() || vec2.empty())
    {
        std::cout << "enpty vector!!!" << std::endl;
        return;
    }
    int vecLength1 = vec1.size();
    int vecLength2 = vec2.size();
    int newLength = vecLength1 + vecLength2;

    int index1 = vecLength1 - 1;
    int index2 = vecLength2 - 1;
    vec1.resize(newLength, 0);
    auto it = vec1.end();
    while (it != vec1.begin() && index1 >= 0 && index2 >= 0)
    {
        --it;
        if (vec1[index1] >= vec2[index2])
        {
            std::cout << " >= "
                      << "1: " << vec1[index1] << " 2: " << vec2[index2] << std::endl;
            *it = vec1[index1];
            --index1;
        }
        else if (vec1[index1] < vec2[index2])
        {
            std::cout << " < "
                      << "1: " << vec1[index1] << " 2: " << vec2[index2] << std::endl;

            *it = vec2[index2];
            --index2;
        }
    }
}

int main()
{
    std::vector<int> vec1 = {1, 3, 5, 7, 8, 10};
    std::vector<int> vec2 = {};

    insertArray(vec1, vec2);
    std::cout << "new vec 1 is: " << std::endl;
    for (auto i : vec1)
    {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
    return 0;
}
