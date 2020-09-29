#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
static bool cmp(string &a, string &b)
{
    int i = 0, j = 0;
    while (a[i] != ' ')
        ++i;
    while (b[j] != ' ')
        ++j;
    string a_content = a.substr(i), b_content = b.substr(j);
    if (a_content != b_content)
        return a_content < b_content;
    return a < b;
}
vector<string> reorderLogFiles(vector<string> &logs)
{
    if (logs.empty())
        return {};
    vector<string> numbers;
    vector<string> res;
    for (auto v : logs)
    {
        int i = 0;
        while (v[i] != ' ')
            ++i;
        ++i;
        //如果是数字日志
        if (isdigit(v[i]))
        {
            numbers.push_back(v);
        }
        //如果是字母日志
        else if (isalpha(v[i]))
        {

            res.push_back(v);
        }
    }

    // 现在res中暂时只有字母日志，要排序。
    sort(res.begin(), res.end(), cmp);

    for (auto num : numbers)
    {
        res.push_back(num);
    }

    return res;
}
int main()
{
    vector<string> logs = {"a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"};
    vector<string> res = reorderLogFiles(logs);
    for (auto v : res)
    {
        cout << v << endl;
    }
    return 0;
}