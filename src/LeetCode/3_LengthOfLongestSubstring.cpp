#include <string>
#include <iostream>
#include <unordered_map>

// int lengthOfLongestSubstring(std::string s)
// {
//     if (s.size() <= 0)
//         return 0;
//     int p1 = 0, p2 = 0, maxLength = 0, currLength = 0;
//     while (p2 < s.size())
//     {
//         char currChar = s[p2];
//         for (int i = p1; i < p2; ++i)
//         {
//             if (currChar == s[i])
//             {
//                 p1 = i + 1;
//                 currLength = p2 - p1;
//                 break;
//             }
//         }
//         ++p2;
//         ++currLength;
//         maxLength = std::max(maxLength, currLength);
//     }
//     return maxLength;
// }

int lengthOfLongestSubstring(std::string s)
{
    if (s.size() <= 0)
        return 0;
    std::unordered_map<char, int> hashMap;
    int p1 = 0, p2 = 0, maxLength = 0, currLength = 0;
    while (p2 < s.size())
    {
        char currChar = s[p2];
        // if (hashMap.find(currChar) != hashMap.end() && hashMap[currChar] >= p1)
        if (hashMap.find(currChar) != hashMap.end())
        {
            int tmpIndex = hashMap[currChar];
            std::cout<<"p1:   "<<p1<<std::endl;
            std::cout<<"p2:   "<<p2<<std::endl;
            std::cout<<"tmpIndex:   "<<tmpIndex<<std::endl;
            p1 = tmpIndex + 1;
            currLength = p2 - p1;
        }
        hashMap[currChar] = p2;
        p2++;
        currLength++;
        maxLength = std::max(maxLength, currLength);
    }
    return maxLength;
}

int main()
{
    std::string s = "abba";
    std::cout << "result:  " << lengthOfLongestSubstring(s) << std::endl;
    return 0;
}