#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
string convert(string s, int numRows)
{
    if(s.size()<=0) return "";
    if(numRows==1) return s; 

    vector<string> res(numRows, "");
    // cout<<res.size()<<endl;
    string ans;
    int flag=1;
    int i=0;
    for(int x=0;x<s.size();++x){
        res[i]+=s[x];
        // cout<<"i: "<<i<<endl;
        if(i==numRows-1 || (i<=0 && x>0))
            flag=-flag;
        i+=flag;
    }
    for(auto a:res){
        // cout<<a<<endl;
        ans+=a;
    }
    return ans;

}
int main()
{
    string str = "ab";
    string res = convert(str, 1);
    cout << res << endl;
}