#include <vector>
#include <iostream>

int trap(std::vector<int> &height)
{
    if(height.size()<3)
        return 0;
    int mr=height[height.size()-1], ml=height[0];
    int ans=0;
    int left=0, right=height.size()-1;
    while(left<=right){
        if(ml<mr){
            if(ml-height[left]>=0){
                ans+=ml-height[left];
            }
            else{
                ml=height[left];
            }
            left++;
        }
        else{
            if(mr-height[right]>=0){
                ans+=mr-height[right];
            }
            else{
                mr=height[right];
            }
            right--;
        }
    }
    return ans;
}

int main()
{
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << trap(height) << std::endl;
}