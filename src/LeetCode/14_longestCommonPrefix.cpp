#include <string>
#include <vector>
#include <iostream>

std::string longestCommonPrefix(std::vector<std::string> &strs)
{
    std::string ans;
    if(strs.size()<=0)
        return ans;
    std::sort(strs.begin(), strs.end());
    int strsLen=strs.size();
    int minLen=std::min(strs[0].size(), strs[strsLen-1].size());
    for(int i=0;i<minLen;++i){
        if(strs[0][i]!=strs[strsLen-1][i]){
            return strs[0].substr(0, i);
        }
    }
    return strs[0].size()>strs[strsLen-1].size()?strs[strsLen-1]:strs[0];
}

int main(){
    std::vector<std::string> strs={"flower", "flow", "flight"};
    // std::sort(strs.begin(), strs.end());
    // for(auto s:strs){
    //     std::cout<<s<<std::endl;
    // }
    std::cout<<longestCommonPrefix(strs)<<std::endl;
}