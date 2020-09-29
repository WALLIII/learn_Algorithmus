#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>
#include<queue>
using namespace std;
class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int val)
    {
        if(maxque.size()==0){
            maxque.push(val);
        }
        
        
        else if (maxque.size() > minque.size())
        {
            if (val >= maxque.top())
            { 
                minque.push(val);
            }
            else
            {
                minque.push(maxque.top());
                maxque.pop();
                maxque.push(val);
            }
        }
        
        else if (maxque.size() == minque.size())
        {
            if (val <= minque.top())
            {
                maxque.push(val);
            }
            else
            {
                maxque.push(minque.top());
                minque.pop();
                minque.push(val);
            }
        }
    }

    double findMedian()
    {
        if(minque.empty()){
            if(maxque.empty()){
                return 0;
            }
            else return maxque.top();
        }

        else if ((maxque.size() + minque.size()) % 2 == 0)
        {
            double res = ((double)maxque.top() + (double)minque.top()) / 2.0;
            return res;
        }
        else
            return maxque.top();
    }

private:
    priority_queue<int, vector<int>, less<int>> maxque;
    priority_queue<int, vector<int>, greater<int>> minque;
};

int main()
{
    MedianFinder mf;
    cout<<mf.findMedian()<<endl;
    mf.addNum(1);
    mf.addNum(2);
    cout<<mf.findMedian()<<endl;
    mf.addNum(3);
    cout<<mf.findMedian()<<endl;
    // double res=mf.findMedian();
    cout<<mf.findMedian()<<endl;
}