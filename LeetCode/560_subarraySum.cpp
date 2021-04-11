#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int subarraySum(vector<int> &nums, int k) {
    if(nums.size()<=0)
        return 0;
    int pre=0, count=0;
    unordered_map<int,int> hash;
    hash[0]=1;
    for(int i=0;i<nums.size();++i){
        pre+=nums[i];
        if(hash.find(pre-k)!=hash.end()){
            count+=hash[pre-k];
        }
        hash[pre]++;
    }
    return count;
}

int main()
{
    vector<int> nums = {3, 4, 7, 2, -3, 1, 4, 2};
    int res=subarraySum(nums, 7);
    cout << res << endl;
}