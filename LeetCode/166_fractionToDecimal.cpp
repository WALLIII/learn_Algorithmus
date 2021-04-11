#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string fractionToDecimal(int a, int b)
{
    if(a==0) return "0";
    //ans保存最终的答案，tmp用来保存临时的小数部分，最后要拼接到ans上
    string ans, tmp = "";
    if ((a > 0) ^ (b > 0))
        ans += '-';
    a = abs(a);
    b = abs(b);
    long long num = a / b;
    long long rem = a % b;
    ans += to_string(num);
    if (rem == 0)
        return ans;
    ans += '.';
    bool flag = true; //用flag表示是否为循环小数，默认为循环小数
    //用哈希表来确认当前的余数rem是否出现过，如果出现过了说明开始循环了，可以跳出while写答案
    //哈希表的key为余数rem，value为这个rem所在的位置，所以需要另外一个cnt来记录现在扫描到了哪一个小数位
    unordered_map<long long, int> mp;
    int cnt = 0;
    while (!mp.count(rem))
    {
        mp[rem] = cnt++;
        rem *= 10;
        num = rem / b;
        tmp += to_string(num);
        rem = rem % b;
        if(rem==0){
            flag=false;
            break;
        }
    }
    //如果是有限小数
    if(!flag)   ans+=tmp;
    else{
        ans+=tmp.substr(0, mp[rem]);
        ans+='(';
        ans+=tmp.substr(mp[rem]); //tmp从index=mp[rem]开始直到末尾的子串
        ans+=')';
    }
    return ans;
}
int main()
{
    string s1 = fractionToDecimal(2, 3);
    string s2 = fractionToDecimal(-1, 4);
    string s3 = fractionToDecimal(-2147483648, -1);
    string s4 = fractionToDecimal(1, 6);
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
}