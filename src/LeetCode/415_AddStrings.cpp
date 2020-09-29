#include <vector>
#include <iostream>
using namespace std;

string addStrings(string num1, string num2)
{
    if (num1.empty())
        return num2;
    if (num2.empty())
        return num1;
    string res = "";
    int tmp = 0, i = 1, carry = 0;
    int n1 = num1.size() - 1, n2 = num2.size() - 1;
    while (n1 >= 0 || n2 >= 0)
    {
        // tmp = num1[n1++]-'0' + num2[n2++] + carry;
        int m=n1>=0?num1[n1]-'0':0;
        int n=n2>=0?num2[n2]-'0':0;
        tmp=m+n+carry;
        carry = tmp / 10;
        res+=to_string(tmp%10);
        n1--;n2--;
    }
    if(carry==1)
        res+="1";
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string str1 = "51189";
    string str2 = "967895";
    string res = addStrings(str1, str2);
    cout << res << endl;
    return 0;
}