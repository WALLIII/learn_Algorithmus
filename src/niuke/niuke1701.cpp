#include <vector>
#include <iostream>

double PowerSeparate(double base, int exponent)
{
    if(exponent==1)
        return base;
    if(exponent==0)
        return 1;
    double result=PowerSeparate(base, exponent>>1);
    result*=result;
    if((exponent&(0x1))==1)
        result*=base;
    return result;
}
double Power(double base, int exponent){
    if(base==0.0&&exponent<=0)
        return -1;
    else if(base!=0.0&&exponent==0)
        return 1.0;
    int absexponent=std::abs(exponent);
    double result=PowerSeparate(base, absexponent);
    if(exponent<0)
        result=1.0/result;
    return result;
}

int main()
{
    std::cout << Power(0, -2) << std::endl;
    // std::cout<<(4>>1);
    return 0;
}
