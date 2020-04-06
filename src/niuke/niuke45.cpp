#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

static bool compare(const std::string &st1, const std::string &st2)
{
    std::string s1 = st1 + st2;
    std::string s2 = st2 + st1;
    std::cout<<"s1: "<<s1<<std::endl;
    std::cout<<"s2: "<<s2<<std::endl;
    return s1 < s2;
}
std::string PrintMinNumber(std::vector<int> numbers)
{
    std::string result;
    if (numbers.size() <= 0)
    {
        return result;
    }
    std::vector<std::string> strNum;
    for (int i = 0; i < numbers.size(); i++)
    {
        std::stringstream ss;
        ss << numbers[i];
        std::string s = ss.str();
        strNum.push_back(s);
    }
   
    sort(strNum.begin(), strNum.end(), compare);

    for (int i = 0; i < strNum.size(); i++)
    {
        result.append(strNum[i]);
    }
    return result;
}

int main(){
    std::vector<int> arr = {3,32,321};
    std::string result;
    result = PrintMinNumber(arr);
    std::cout<<result<<std::endl;
    return 0;
}