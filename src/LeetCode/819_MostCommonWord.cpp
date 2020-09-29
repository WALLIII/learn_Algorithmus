#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string mostCommonWord(string paragraph, vector<string> &banned)
{
    if (paragraph.empty())
        return "";
    unordered_map<string, int> hash;
    int i = 0;
    while (i < paragraph.size())
    {
        string tmp = "";
        while (isalpha(paragraph[i]) && i < paragraph.size())
        {
            tmp += tolower(paragraph[i]);
            ++i;
        }

        hash[tmp]++;
        while (!isalpha(paragraph[i]) && i < paragraph.size())
            ++i;
    }

    int max = INT_MIN;
    string res = "";
    for (auto v : hash)
    {
        if (v.second > max)
        {
            if (banned.empty())
            {
                max = v.second;
                res = v.first;
            }
            else if (!banned.empty())
            {
                if (find(banned.begin(), banned.end(), v.first) == banned.end())
                {
                    max = v.second;
                    res = v.first;
                }
            }
        }
    }
    return res;
}
int main()
{
    string s = "Bob. hIt, baLl";
    vector<string> banned = {"bob", "hit"};
    // string s = "a.";
    // vector<string> banned;
    cout << mostCommonWord(s, banned) << endl;
}