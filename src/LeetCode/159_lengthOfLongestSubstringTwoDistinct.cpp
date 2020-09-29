#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int lengthOfLongestSubstringTwoDistinct(string s)
{
    if (s.size() <=0)
        return 0;
    int p1 = 0, p2 = 0, maxLen = 0, currLen = 0;
    unordered_map<char, int> hash;
    while (p2 < s.size())
    {
        hash[s[p2]]++;
        
        while(hash.size()>2){
            hash[s[p1]]--;
            if(hash[s[p1]]==0)
                hash.erase(s[p1]);
            ++p1;
        }
        maxLen = max(maxLen, p2-p1+1);
        p2++;
    }
    return maxLen;
}    

    int main()
    {
        string s1 = "eceba", s2 = "ccaabbb", s3 = "abcabcbb";
        // cout << s1 << "   " << lengthOfLongestSubstringTwoDistinct(s1) << endl;
        // cout << s2 << "   " << lengthOfLongestSubstringTwoDistinct(s2) << endl;
        cout<<lengthOfLongestSubstringTwoDistinct("ababacccccc") << endl;
        // cout << s3 << "   " << lengthOfLongestSubstringTwoDistinct(s3) << endl;
        return 0;
    }