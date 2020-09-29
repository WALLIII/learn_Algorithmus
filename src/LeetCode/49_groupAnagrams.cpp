#include <map>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs){
    if(strs.size()<=0)
        return {};
    double a[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    unordered_map<double, vector<string>> hash;
    vector<vector<string>> res;
    for(auto str:strs){
        double mul=1;
        for(auto c:str){
            mul*=a[c-'a'];
        }
        hash[mul].push_back(str);
    }
    for(auto n:hash){
        res.push_back(n.second);
    }
    return res;
}
// vector<vector<string>> groupAnagrams(vector<string> &strs)
// {
//     if (strs.size() <= 0)
//         return {};
//     vector<vector<string>> res;
//     unordered_map<string, vector<string>> hash;
//     for (auto str : strs)
//     {
//         string tmp = str;
//         sort(tmp.begin(), tmp.end());
//         hash[tmp].push_back(str);
//     }
//     for (auto item : hash)
//     {
//         res.push_back(item.second);
//     }
//     return res;
// }
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for (auto str : res)
    {
        for (auto s : str)
        {
            cout << s << "  ";
        }
        cout << endl;
    }
    return 0;
}