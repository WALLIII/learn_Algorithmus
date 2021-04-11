#include <string>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <vector>
#include<map>

using namespace std;
typedef pair<int, string> P;

struct Order
{
    bool operator()(const P &a, const P &b)
    {
        return (a.first > b.first || (a.first == b.first && a.second < b.second));
    }
};

vector<string> topKFrequent(vector<string> &words, int k)
{
    if (words.size() <= 0)
        return {};
    unordered_map<string, int> hash;
    vector<string> res;
    Order ord;
    for (int i = 0; i < words.size(); ++i)
    {
        hash[words[i]]++;
    }
    priority_queue<P, vector<P>, Order> pq;
    for(auto item:hash){
        P tmp{item.second, item.first};
        if(pq.size()<k)
            pq.push(tmp);
        else if(ord(tmp, pq.top())){
            pq.push(tmp);
            pq.pop();
        }
    }
    while(k--){
        res.push_back(pq.top().second);
        pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<string> words{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    vector<string> res = topKFrequent(words, 4);
    for (auto a : res)
    {
        cout << a << endl;
    }
    return 0;
}