#include <iostream>
#include <vector>
#include <algorithm>
// time out solution
// bool isUgly(int number){
// 	while(number%2==0){
// 		number/=2;
// 		// std::cout<<number<<"   ";
// 	}
// 	while(number%3==0){
// 		number/=3;
// 		// std::cout<<number<<"   ";
// 	}
// 	while(number%5==0){
// 		number/=5;
// 		// std::cout<<number<<"   ";
// 	}
// 	if(number==1)
// 		return true;
// 	else
// 		return false;
// }
// int GetUglyNumber_Solution(int index)
// {
// 	if(index<=0)
// 		return -1;
// 	int number = 1;
// 	int uglyFound=1;
// 	while(uglyFound<=index){
// 		if(isUgly(number))
// 			uglyFound++;
// 		number++;
// 	}
// 	return number-1;
// }

int GetUglyNumber_Solution(int index)
{
	if (index == 0)
		return 0;
	std::vector<int> uglyRes;
	uglyRes.push_back(1);
	int p2 = 0, p3 = 0, p5 = 0;
	while(uglyRes.size()<index){
		int min=std::min(uglyRes[p2]*2, std::min(uglyRes[p3]*3, uglyRes[p5]*5));
		uglyRes.push_back(min);
		if(uglyRes[p2]*2==min) p2++;
		if(uglyRes[p3]*3==min) p3++;
		if(uglyRes[p5]*5==min) p5++;
	}
	return uglyRes[index-1];

}

int main()
{
	std::cout<<"ugly number:  "<<GetUglyNumber_Solution(15)<<std::endl;
	
	return 0;
}