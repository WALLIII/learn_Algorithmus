#include <iostream>

// bool isPowerOfTwo(int n)
// {
    // if(n==0)
    //     return false;
    // while(n%2==0){
    //     n=n>>1;
    // }
    // return n==1;
// }
bool isPowerOfTwo(int n){`
    if(n<=0)
        return false;
    if((n & (n-1)))
        return false;
   else
        return true;
    
}
int main()
{
    // if(isPowerOfTwo(8))
    //     std::cout<<"is true"<<std::endl;
    // else
        // std::cout<<"is false"<<std::endl;
    for(int i=0;i<129;++i){

    if(isPowerOfTwo(i))
        std::cout<<"i: "<<i<<" is true"<<std::endl;
    else if (!isPowerOfTwo(i))
        std::cout<<"i: "<<i<<" is false"<<std::endl;
    }
    return 0;
}