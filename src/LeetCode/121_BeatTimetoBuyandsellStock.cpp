#include <iostream>
#include <vector>

int maxProfit(std::vector<int> &prices)
{
    if(prices.size()<=1)
        return 0;
    int minprice=INT_MAX, maxprofit=0;
    for(int i=0;i<prices.size();++i){
        minprice=prices[i]>minprice?minprice:prices[i];
        if(prices[i]-minprice>maxprofit)
            maxprofit=prices[i]-minprice;
    }
    return maxprofit;
}

int main()
{
    std::vector<int> prices = {7, 6,5,4,3,2};
    std::cout << maxProfit(prices) << std::endl;
    return 0;
}