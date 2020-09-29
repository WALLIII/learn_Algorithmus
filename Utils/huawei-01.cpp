#include <string>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

void reverse(string &s, int begin, int end){
    if(begin>=end) return;
    while(begin<=end){
        swap(s[begin], s[end]);
        ++begin;
        --end;
    }
        //cout<<s<<endl;
    return;
}
string convert(string s)
{
    string copy = "";
    int i = 0;
    while (i < s.size())
    {
        string word;
        while(i < s.size() && !isalpha(s[i]) && !isdigit(s[i]) && s[i]!='-'){
            
            ++i;
        }
        while ( i < s.size() && (isalpha(s[i]) || isdigit(s[i])))
        {
            //cout<<s[i]<<endl;
            word += s[i];
            ++i;
        }
        //cout<<word<<endl;
        if (s[i] == '-')
        {
            //如果-的左右两边是字母或者数字，这个是连接符，要加入word
            if (i>0 && (isdigit(s[i - 1]) || isalpha(s[i - 1])) && (isdigit(s[i + 1]) || isalpha(s[i + 1])))
            {
                word += s[i];
                ++i;
                while ( i < s.size() && (isalpha(s[i]) || isdigit(s[i])))
                {
                    //cout<<"aa"<<endl;
                    word += s[i];
                    ++i;
                }
                //++i;
            }
            else ++i;
        }
        if(word.size()>0)       
            copy+=word+" ";
    }
    copy=copy.substr(0, copy.size()-1);
    reverse(copy, 0, copy.size()-1);
    cout<<copy<<endl;
    int begin=0, end=0, len=0;
    while(begin<=end && end<copy.size()){
        len=0;
        while(end<copy.size() && copy[end]!=' '){
            len++;
            end++;
        }
        begin=end-len;
        //cout<<"b: "<<copy[begin]<<"  e: "<<copy[end-1]<<" len: "<<len<<endl;
        reverse(copy, begin, end-1);
        ++end;
    }

    return copy;
}

int main()
{
    string s="-I am an 20-years out--standing @ * -stu- dent--";
    // getline(cin, s);
    string res = convert(s);
    cout << res << endl;
}