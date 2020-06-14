#include <iostream>

// int hammingDistance(int x, int y)
// {
//     int n=x^y;
//     int count=0;
//     while(n){
//         n=n&(n-1);
//         count++;
//     }
//     return count;
// }

int hammingDistance(int x, int y){
    int n=x^y;
    int count=0;
    while(n){
        if((n&1)==1)
            count++;
        n>>=1;
    }
    return count;
}

int main()
{
    std::cout << hammingDistance(1, 4) << std::endl;
    return 0;
}