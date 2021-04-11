#include <vector>
#include <iostream>
using namespace std;

string addBinary(string a, string b) {
        if(a.size()<=0) return b;
        if(b.size()<=0) return a;
        int l1=a.size()-1, l2=b.size()-1;
        string res="";
        int tmp=0, carry=0;
        while(l1>=0 ||l2>=0){
            int m=l1>=0?a[l1]-'0':0;
            int n=l2>=0?b[l2]-'0':0;
            tmp=m+n+carry;
            carry=tmp/2;
            res+=to_string(tmp%2);
            l1--;l2--;
        }
        if(carry==1)
            res+='1';
        reverse(res.begin(), res.end());
        return res;
    }
int main()
{
    string num1="1011", num2="100";
    string res=addBinary(num1, num2);
    cout<<res<<endl;
    return 0;
}