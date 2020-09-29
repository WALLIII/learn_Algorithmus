#include <iostream>
int  NumberOf1(int n) {
       int count=0;
       while(n){
           ++count;
           n=(n-1)&n;
       }  
       return count;
}
int main(){
    std::cout<<NumberOf1(-10)<<std::endl;
}