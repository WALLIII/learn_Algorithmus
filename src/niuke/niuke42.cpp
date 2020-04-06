#include <vector>
#include <iostream>

int FindGreatestSumOfSubArray(std::vector<int> array)
{
    int len = array.size();
    int maximum = INT_MIN;
    int currSum = 0;
    if (len <= 0)
        return maximum;
    for (int i = 0; i < len; ++i)
    {
        if (currSum <= 0)
        {
            currSum = array[i];
        }
        else
        {
            currSum += array[i];
        }
        if (currSum > maximum)
        {
            maximum = currSum;
        }
    }
    return maximum;
}

int main(){
    std::vector<int> array = {1,-2,3,10,-4,7,2,-5};
    std::cout<<FindGreatestSumOfSubArray(array)<<std::endl;
    return 0;
}