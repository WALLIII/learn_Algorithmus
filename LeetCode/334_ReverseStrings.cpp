#include<string>
#include<vector>
#include<iostream>

 void reverseString(std::vector<char>& s) {
    if(s.size()<=1)
        return;
    int p1=0, p2=s.size()-1;
    while(p1<p2){
        char tmp=s[p1];
        s[p1]=s[p2];
        s[p2]=tmp;
        ++p1;
        --p2;
    }
 }

int main(){
    std::vector<char> s={'h', 'l', 's', 'f', 'p'};
    reverseString(s);
    for(auto ch:s){
        std::cout<<ch<<"  ";
    }
}