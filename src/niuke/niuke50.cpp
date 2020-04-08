#include <string>
#include <iostream>
#include <vector>

int FirstNotRepeatingChar(std::string str)
{
    if(str.size()<=0)
        return -1;
    int hashTable[256]={0};
    for(int i=0;i<str.size();++i){
        hashTable[(int)str[i]]++;
    }
    for(int i=0;i<str.size();++i){
        if(hashTable[str[i]]==1){
            return i;
        }
    }
    return -1;
}

int main(){
    std::string str="ddnnaassdqdq";
    std::cout<<FirstNotRepeatingChar(str)<<std::endl;
    return 0;
}