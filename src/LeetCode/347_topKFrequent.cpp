#include <string>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <vector>
#include<map>

using namespace std;
typedef pair<int,int> P;
struct Order
{
    bool operator()(const P&a, const P&b){
        return a.second>b.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k){
    if(nums.size()<=0)
        return {};
    unordered_map<int,int> hash;
    priority_queue<P, vector<P>, Order> pq;
    vector<int> res;
    Order ord;
    for(int i=0;i<nums.size();++i)  hash[nums[i]]++;
    for(auto item:hash){
        if(pq.size()<k){
            pq.push(make_pair(item.first, item.second));
        }
        else if(ord(make_pair(item.first, item.second), pq.top())){
            pq.push(make_pair(item.first, item.second));
            pq.pop();
        }
    }
    while(k--){
        res.push_back(pq.top().first);
        pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;

}
int main()
{
    vector<int> words{1,3,2,4,1,3,2,5,5,5,5};
    vector<int> res = topKFrequent(words, 4);
    for (auto a : res)
    {
        cout << a << endl;
    }
    return 0;
}