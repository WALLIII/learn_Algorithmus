#include <vector>
#include <iostream>
#include<unordered_map>
bool containsDuplicate(std::vector<int> &nums)
{
    std::unordered_map<int, int> hashTable;
    for(int i=0;i<nums.size();++i){
        hashTable[nums[i]]++;
        if(hashTable[nums[i]]>1)
            return true;
    }
    return false;
}

int main(){
    std::vector<int> nums={1,2,3};
    if(containsDuplicate(nums)==true)
        std::cout<<"has duplicates number"<<std::endl;
    else
        std::cout<<"no duplicate"<<std::endl;
    return 0;
}