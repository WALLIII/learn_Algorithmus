#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int> &candidates, vector<vector<int>> &res, vector<int> &path, int start, int target)
{
    if (target == 0)
    {
        res.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size(); ++i)
    {
        if (target - candidates[i] < 0)
            break;
        path.push_back(candidates[i]);
        backtrack(candidates, res, path, i, target - candidates[i]);
        path.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    int len = candidates.size();
    if (len <= 0)
        return {};
    vector<vector<int>> res;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, res, path, 0, target);
    return res;
}
int main()
{
    vector<int> candidates = {2, 3, 5, 7};
    vector<vector<int>> res = combinationSum(candidates, 7);
    for (auto aa : res)
    {
        for (auto a : aa)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}
