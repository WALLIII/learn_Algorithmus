#include <vector>
#include <iostream>


// 动态规划
int trap(std::vector<int> &height)
{
    if (height.size() == 0)
    {
        return 0;
    }
    int n = height.size();
    std::vector<int> maxleft(n);
    std::vector<int> maxright(n);
    int ans = 0;
    maxleft[0] = height[0];
    maxright[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
    {
        maxleft[i] = std::max(height[i], maxleft[i - 1]);
    }
    // std::cout << "maxleft:  ";
    // for (int a : maxleft)
    //     std::cout << a << "  ";
    std::cout << std::endl;
    for (int j = n - 2; j > -1; j--)
    {
        maxright[j] = std::max(height[j], maxright[j + 1]);
    }
    // std::cout << "maxright:  ";
    // for (int a : maxright)
    //     std::cout << a << "  ";
    // std::cout << std::endl;
    for (int k = 0; k < n; k++)
    {
        if (std::min(maxleft[k], maxright[k]) > height[k])
        {
            ans += std::min(maxleft[k], maxright[k]) - height[k];
        }
    }
    return ans;
}
// 改进的动态规划：双指针
// int trap(std::vector<int> &height)
// {
//     if(height.size()<3)
//         return 0;
//     int mr=height[height.size()-1], ml=height[0];
//     int ans=0;
//     int left=0, right=height.size()-1;
//     while(left<=right){
//         if(ml<mr){
//             if(ml-height[left]>=0){
//                 ans+=ml-height[left];
//             }
//             else{
//                 ml=height[left];
//             }
//             left++;
//         }
//         else{
//             if(mr-height[right]>=0){
//                 ans+=mr-height[right];
//             }
//             else{
//                 mr=height[right];
//             }
//             right--;
//         }
//     }
//     return ans;
}

int main()
{
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << trap(height) << std::endl;
}