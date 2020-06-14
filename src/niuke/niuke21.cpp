#include <iostream>
#include <vector>
// 利用插入排序法的方法，不开辟新的数组。我们找到奇数的时候，就把奇数前面的偶数都移到它后面
void reOrderArray1(std::vector<int> &array){
    if(array.size()<=1)
        return;
    for(int i=0;i<array.size();++i){
        if(array[i]%2==1){
            int tmp=array[i];
            int j=i-1;
            while(j>=0&&array[j]%2==0){
                array[j+1]=array[j];
                --j;
            }
            array[j+1]=tmp;
        }
    }
}

// 开辟辅助数组的方法
void reOrderArray(std::vector<int> &array){
    if(array.size()<=1)
        return;
    std::vector<int> odd(0);
    int size=array.size(), p1=0, p2=0;
    while(p1<size&&p2<size){
        while(p2<size&&array[p2]%2==0){
            odd.push_back(array[p2]);
            p2++;
        }
        if(p2>=size)
            break;
        array[p1]=array[p2];
        p1++;
        p2++;
    }
    
    int j=0;
    for(int i=p1;i<size;++i){
        array[i]=odd[j];
        ++j;
    }
}
int main()
{
    
    std::vector<int> vec2 = {1,2,3,4,5,6,7};

    
    reOrderArray(vec2);

    for (auto v2 : vec2)
    {
        std::cout << v2 << "   ";
    }
    std::cout << std::endl;
    return 0;
}
