#include <vector>
#include <iostream>
using namespace std;

vector<string> num1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                       "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};
vector<string> num2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
vector<string> num3 = {"Hundred", "Thousand", "Million", "Billion"}; //前面增加空字符串,方便单词数字与下标对应

string helper(int num)
{
    if(num==0)
        return "";
    if(num<20)
        return " "+num1[num];
    if(num<100)
        return " "+num2[num/10]+helper(num%10);
    //100~1000
    if(num<1000)
        return helper(num/100)+" "+num3[0]+helper(num%100);
    //1k~10w(million)
    if(num<1000000){
        return helper(num/1000)+" "+num3[1]+helper(num%1000);
    }
    if(num<1000000000){
        return helper(num/1000000)+" "+num3[2]+helper(num%1000000);
    }
    if(num>=1000000000 && num<INT_MAX){
        return helper(num/1000000000)+" "+num3[3]+helper(num%1000000000);
    }
    else
        return "";
    
}
string numberToWords(int num)
{
    if (num == 0)
        return "Zero";
    string res = helper(num);
    res.erase(0,1);
    return res;
}
int main()
{
    string res = numberToWords(2147483647);
    cout << res<<"flag"<<endl;

    return 0;
}