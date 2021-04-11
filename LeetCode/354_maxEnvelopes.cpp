#include <vector>
#include <iostream>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    if (envelopes.size() <= 0)
        return 0;
    int size = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), cmp);
    // for (auto env : envelopes)
    // {
    //     for (auto a : env)
    //         cout << a << "  ";
    //     cout << endl;
    // }
    vector<int> dp(size, 1);
    int res=0;
    for(int i=0;i<size;++i){
        for(int j=0;j<i;++j){
            if(envelopes[j][1]<envelopes[i][1]){
                dp[i]=max(dp[j]+1, dp[i]);
            }
        }
        res=max(res, dp[i]);
    }
    return res;
}

int main(){
    vector<vector<int>> envelops={{5,4}, {6,4}, {6,7},{2,3}};
    int res=maxEnvelopes(envelops);
    cout<<"res:  "<<res<<endl;
}