#include <iostream>
#include <vector>

int maxProfit(std::vector<int> &prices)
{
    if(prices.size()<=1)
        return 0;
    int maxprofit=0;
    for(int i=0;i<prices.size()-1;++i){
        if(prices[i+1]>prices[i])
            maxprofit=maxprofit+prices[i+1]-prices[i];
    }
    return maxprofit;
}

int main()
{
    std::vector<int> prices = {7,1,5,3,6,4};
    std::cout << maxProfit(prices) << std::endl;
    return 0;
}
