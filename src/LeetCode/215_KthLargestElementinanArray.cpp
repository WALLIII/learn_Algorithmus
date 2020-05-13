#include <queue>
#include <vector>
#include <iostream>

int findKthLargest(std::vector<int> &nums, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (auto n : nums)
    {
        if(pq.size()>=k&&pq.top()>n)
            continue;
        pq.push(n);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}

int main()
{
    std::vector<int> nums = {5, 4, 3, 7, 6};
    std::cout << findKthLargest(nums, 2) << std::endl;
    return 0;
}