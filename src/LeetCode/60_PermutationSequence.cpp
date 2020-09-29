#include <vector>
#include <iostream>
using namespace std;
int fac(int n){
    int res=1;
    for(int i=1;i<=n;++i)
        res*=i;
    return res;
}

string getPermutation(int n, int k)
{
    if(n<=0)
        return "";
    if(n==1)
        return "1";
    string s=string("123456789").substr(0,n);
    string res;
    vector<int> facto(n);
    for(int i=1;i<n;++i){
        facto[i]=fac(i);
    }
    --k;
    while(k>0){
        // facto[n-1]=(n-1)!, i表示当前位现在要取多少
        int i=k/facto[n-1];
        res+=s[i];
        s.erase(s.begin()+i);
        k=k%facto[n-1];
        --n;
    }
    res+=s;
    return res;
}
int main()
{
    string res = getPermutation(4, 9);
    cout << res << endl;
  
    return 0;
}