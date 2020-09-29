#include <string>
#include <iostream>
#include <vector>

class Solution
{
public:
    std::string s;
    char hashTable[256] = {0};
    //Insert one char from stringstream
    void Insert(char ch)
    {
        s+=ch;
        hashTable[(int)ch]++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(int i=0;i<s.size();++i){
            if(hashTable[s[i]]==1)
                return s[i];
        }
        return '#';
    }
};

int main()
{
    std::string str = "ddnnaassdqdq";
    std::cout << FirstNotRepeatingChar2(str) << std::endl;
    return 0;
}