#include <vector>
#include <iostream>
// 法一：用逻辑运算判断递归出口
// int Sum_Solution(int n)
// {
//     bool x=(n>1)&&(n+=Sum_Solution(n-1));
//     return n;    
// }
// 移位加法来实现乘法的写法：
int Multi2(int a, int b){
    int res=0;
    while(a!=0){
        if((a&1)!=0)
            res+=b;
        a>>=1;
        b<<=1;
    }
    return res;
}
static int res=0;
int multi(int a, int b){
    a && multi(a>>1, b<<1);
    (a&1) && (res+=b);
    return res; 
}
int Sum_Solution(int n){
    res=0;
    return (multi(n, n+1)>>1);
}

int main(){
    std::cout<<Sum_Solution(6)<<std::endl;
}