#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

bool cmp(int a, int b){
    return std::to_string(a)+std::to_string(b)<std::to_string(b)+std::to_string(a);
}
std::string PrintMinNumber(std::vector<int> arr)
{
    if(arr.size()<=0)
        return "";
    std::sort(arr.begin(), arr.end(), cmp);
    std::string res="";
    for(auto a:arr){
        res+=std::to_string(a);
    }    
    return res;
}
int main(){
    std::vector<int> arr = {3,32,321};
    std::string result;
    result = PrintMinNumber(arr);
    std::cout<<result<<std::endl;
    return 0;
}