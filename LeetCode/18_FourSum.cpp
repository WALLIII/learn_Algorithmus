#include <vector>
#include <iostream>

std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
{
    std::vector<std::vector<int>> ans;
    std::vector<int> tmp;
    std::sort(nums.begin(), nums.end());
    if (nums.size() < 4)
        return ans;
    for (int i = 0; i < nums.size() - 3; ++i)
    {   if(i>0&&nums[i]==nums[i-1])
            continue;
        for (int j = i+1; j < nums.size() - 2; ++j)
        {
            if(j>i+1&&nums[j]==nums[j-1])
                continue;
            int c = j+1, d = nums.size() - 1;
            while (c < d)
            {
                int sum = nums[i] + nums[j] + nums[c] + nums[d];
                if (sum == target)
                {
                    tmp = {nums[i], nums[j], nums[c], nums[d]};
                    ans.push_back(tmp);
                    tmp.clear();
                    while(c<d&&nums[c]==nums[c+1])
                        ++c;
                    while(c<d&&nums[d]==nums[d-1])
                        --d;
                    c++;d--;
                }
                else if (sum < target)
                {
                    c++;
                }
                else
                {
                    d--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    std::vector<int> numbers = {0,0,0,0};
    std::vector<std::vector<int>> ans;
    ans = fourSum(numbers, 0);
    for (auto tmp : ans)
    {
        for (auto a : tmp)
            std::cout << a << "  ";
        std::cout << std::endl;
    }
}