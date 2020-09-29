
#include<string>
#include<iostream>

// 字符串第一个只出现一次的字符
int FirstNotRepeatingChar(std::string str)
{
    if (str.size() <= 0)
        return -1;
    int hashTable[256] = {0};
    for (int i = 0; i < str.size(); ++i)
    {
        hashTable[(int)str[i]]++;
    }
    for (int i = 0; i < str.size(); ++i)
    {
        if (hashTable[str[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

int main(){
    std::cout<<FirstNotRepeatingChar("aabsdsd")<<std::endl;
}