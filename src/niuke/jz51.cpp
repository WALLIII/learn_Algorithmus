#include <iostream>
#include <vector>

std::vector<int> multiply(const std::vector<int> &A)
{
    std::vector<int> res(A.size(), 1);
    if (A.size() <= 0){
        return res;
    }
    res[0] = 1;
    int curMul = 1, size=A.size();
    for (int i = 1; i < A.size(); ++i)
    {
        curMul *= A[i - 1];
        res[i] = curMul;
    }
    for (auto a : res)
    {
        std::cout << a << "   ";
    }
    std::cout << std::endl;
    curMul =1;
    for (int i = size - 2; i >= 0; --i)
    {        
       curMul*=A[i+1];
       res[i]=res[i]*curMul;

    }
    return res;
}

int main()
{
    std::vector<int> array = {1, 2, 3, 4};
    std::vector<int> res = multiply(array);
    for (auto a : res)
    {
        std::cout << a << "   ";
    }
    std::cout << std::endl;
    return 0;
}
