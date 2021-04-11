#include <vector>
#include <iostream>

int maxScoreSightseeingPair(std::vector<int> &A)
{
    if(A.size()<=1)
        return INT_MIN;
    int preMax=A[0]+0;
    int max=INT_MIN;
    for(int j=1;j<A.size();++j){
        max=max>(preMax+A[j]-j)?max:(preMax+A[j]-j);
        preMax=preMax>(A[j]+j)?preMax:(A[j]+j);
    }
    return max;
   
}

int main()
{
    std::vector<int> A = {8, 1, 5, 2, 6};
    std::cout << maxScoreSightseeingPair(A) << std::endl;
    return 0;
}