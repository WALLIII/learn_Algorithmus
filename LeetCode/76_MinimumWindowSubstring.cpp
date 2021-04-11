#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <typeinfo>
using namespace std;
bool isExisted(unordered_map<char, int> &ori, 
               unordered_map<char, int> &window)
{
    for (auto ch : ori)
    {
        if (window[ch.first] < ch.second)
        {
            return false;
        }
    }
    return true;
}
string minWindow(string s, string t)
{
    if (s.empty() || t.empty() || s.size() < t.size())
        return "";
    unordered_map<char, int> ori, window;
    // ori用来给t中的个个字符做计数。
    for (int i = 0; i < t.size(); ++i)
    {
        ori[t[i]]++;
    }
    // 建立两个指针l和r来构成一个滑窗
    int l = 0, r = 0;
    // ans为最终的答案, len当前最小的长度
    string ans = "";
    int len = INT_MAX;
    while (r < static_cast<int>(s.size()))
    {
        if (ori.find(s[r]) != ori.end())
        {
            window[s[r]]++;
        }
        
        // 如果找到
        while (isExisted(ori, window) && l <= r)
        {
            if ((r - l + 1) < len)
            {
                len = r - l + 1;
                ans = s.substr(l, len);
                cout << ans << endl;
            }

            if (ori.find(s[l]) != ori.end())
            {
                --window[s[l]];
            }
            ++l;
        }
        ++r;
    }
    return ans;
}

int main()
{
    // string s = "ADOBECODEBANC";
    // string t = "ABC";
    string s = "ab";
    string t = "a";
    std::cout << minWindow(s, t) << std::endl;
    // std::cout << s << std::endl;
}