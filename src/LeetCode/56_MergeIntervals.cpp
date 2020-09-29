#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return {};
    vector<vector<int>> merged;
    sort(intervals.begin(), intervals.end());
  
    merged.push_back({intervals[0][0], intervals[0][1]});
    for (int i = 1; i < intervals.size(); ++i)
    {
        auto back = merged.back();
        int lnew = intervals[i][0], rnew = intervals[i][1];
        int lback = back[0], rback = back[1];
        if (lnew > rback)
        {
            merged.push_back({lnew, rnew});
        }
        else{
            merged.back()[1]=rnew>rback?rnew:rback;
        }
    }
    return merged;
}

int main()
{
    vector<vector<int>> intervals(8, vector<int>(2, 0));
    int interval[8][2] = {{1, 9},
                          {2, 5},
                          {19, 20},
                          {10, 11},
                          {12, 20},
                          {0, 3},
                          {0, 1},
                          {0, 2}};
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            intervals[i][j] = interval[i][j];
        }
    }
    vector<vector<int>> res = merge(intervals);
    for (auto tmp : res)
    {
        for (auto a : tmp)
            cout << a << "   ";
        cout << endl;
    }

    return 0;
}