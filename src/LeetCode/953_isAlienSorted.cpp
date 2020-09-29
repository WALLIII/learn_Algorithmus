#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
bool isAlienSorted(vector<string> &words, string order)
{
    //先建立哈希表把字母对应的新顺序下下来
    map<char, int> mp;
    for (int i = 0; i < order.size(); ++i)
        mp[order[i]] = i;
    int flag = 0, i, j;
    for (i = 0; i < words.size() - 1; ++i)
    {
        for (j = 0; j < min(words[i].size(), words[i + 1].size()); ++j)
        {
            if (mp[words[i][j]] < mp[words[i + 1][j]]){
                break;
            }
            if (mp[words[i][j]] > mp[words[i + 1][j]])
                return false;
        }
        // mp[words[i][j]]<mp[words[i+i][j]]:如果words[i]比words[i + 1]长，但是首字母比后者靠前的话，也算前者小
        if (mp[words[i][j]]<mp[words[i+1][j]] || words[i].size() < words[i + 1].size())
            flag++;
    }
    if (flag == words.size() - 1)
        return true;
    else
        return false;
}
int main()
{
    vector<string> words = {"word", "world", "row"};
    string order = "worldabcefghijkmnpqstuvxyz";
    vector<string> words1 = {"apple","app"};
    string order1 = "abcdefghijklmnopqrstuvwxyz";
     vector<string> words2 = {"kuvp","q"};
    string order2 = "ngxlkthsjuoqcpavbfdermiywz";
    // cout << isAlienSorted(words, order) << endl;
    // cout << isAlienSorted(words1, order1) << endl;
    cout << isAlienSorted(words2, order2) << endl;
}