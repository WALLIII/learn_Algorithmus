#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

bool IsContinuous(std::vector<int> numbers)
{
    if (numbers.size() != 5)
        return false;
    int zeros = 0, gaps = 0;
    int i = 0;
    std::sort(numbers.begin(), numbers.end());
    for(auto a: numbers){
        std::cout<<a<<" ";
    }
    std::cout<<std::endl;
    while (i < 5 && numbers[i] == 0)
    {
        zeros++;
        i++;
    }
    std::cout<<"zeros:  "<<zeros<<std::endl;
    i = zeros;
    while (i < 4)
    {
        if (numbers[i + 1] == numbers[i])
        {
            return false;
        }
        
        gaps+=numbers[i + 1] - numbers[i]-1;
       
        i++;
    }
    std::cout<<"gaps:  "<<gaps<<std::endl;
    if (zeros >= gaps)
        return true;
    else
        return false;
}
int main()
{
    std::vector<int> numbers = {1,3,0,0,7};
    if(IsContinuous(numbers))
        std::cout<<"IsContinuous!!!"<<std::endl;       
    else
        std::cout<<"not Continuous!!!"<<std::endl;               
    return 0;
}