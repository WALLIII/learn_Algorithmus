#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


void backtrack(int index, string digits, vector<string> &ans, string &current,unordered_map<int, string> &hash )
{
    if (index == digits.size())
    {
        ans.push_back(current);
        for (auto a : ans)
        {
            cout << a << endl;
        }
    }
    for (int i = 0; i < hash[digits[index]].size(); ++i)
    {
        current.push_back(hash[digits[index]][i]);
        backtrack(index + 1, digits, ans, current, hash);
        current.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    unordered_map<char, string> hash = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    if (digits.size() <= 0){
        
        return {};
    }
    vector<string> ans;
    string current = "";
    backtrack(0, digits, ans, current, hash);
    return ans;
}
int main()
{
    string digits="23";
    vector<string> res=letterCombinations(digits);

    for (auto a : res)
    {
        cout << a << endl;
    }
    return 0;
}