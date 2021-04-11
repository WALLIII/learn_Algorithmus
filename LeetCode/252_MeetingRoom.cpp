#include <vector>
#include <iostream>
using namespace std;

bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()<=0)
            return true;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for(int i=0;i<intervals.size();++i){
            int l=intervals[i][0], r=intervals[i][1];
            if(merged.empty() || l>=merged.back()[1]){
                merged.push_back({l,r});
            }
            else{
                merged.back()[1]=max(merged.back()[1], r);
            }
        }
        if(merged.size()==intervals.size())
            return true;
        else return false;

    }
int main()
{
    vector<vector<int>> intervals(2, vector<int>(2, 0));
    int interval[2][2] = {{13,15},
                          {1,13}};
    cout<<merge(intervals)<<endl;;
    
    
    return 0;
}