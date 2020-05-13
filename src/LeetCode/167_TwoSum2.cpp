#include <vector>
#include <iostream>

std::vector<int> twoSum(std::vector<int> &numbers, int target)
{
    std::vector<int> ans;
    int p1=0, p2=numbers.size()-1;
    while(p1<p2){
        if(numbers[p1]+numbers[p2]==target)
            return{(p1+1), (p2+1)};
        else if(numbers[p1]+numbers[p2]<target){
            p1++;
        }
        else{
            p2--;
        }
    }
    return ans;
}

int main()
{
    std::vector<int> numbers = {2, 7, 11, 15};
    std::vector<int> ans;
    ans = twoSum(numbers, 25);
    for(auto a:ans)
        std::cout<<a<<"  ";
}