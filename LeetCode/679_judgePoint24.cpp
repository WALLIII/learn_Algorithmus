#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

static constexpr int TARGET = 24;
static constexpr double EPSILON = 1e-6;
static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

bool solve(vector<double> &list)
{
    if (list.size() == 0)
        return false;
    //list长度为1时，就是得出了最终的答案，判断这个答案是否为24
    if (list.size() == 1)
        return fabs(list[0] - TARGET) < EPSILON;
    int size = list.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (j != i)
            {
                vector<double> list2;
                //先把这次没有拿去做四则运算的数字放进list2，用于递归
                for (int k = 0; k < size; ++k)
                {
                    if (k != i && k != j)
                        list2.push_back(list[k]);
                }
                for (int k = 0; k < 4; ++k)
                {
                    //加法和乘法都满足交换律，因此如果选择的运算操作是加法或乘法，
                    //则对于选出的 22 个数字不需要考虑不同的顺序，在遇到第二种顺序时可以不进行运算，直接跳过。
                    if (k < 2 && i > j)
                        continue;
                    if (k == ADD)
                    {
                        list2.push_back(list[i] + list[j]);
                    }
                    else if (k == MULTIPLY)
                    {
                        list2.push_back(list[i] * list[j]);
                    }
                    else if (k == SUBTRACT)
                    {
                        list2.push_back(list[i] - list[j]);
                    }
                    else if (k == DIVIDE)
                    {
                        if (fabs(list[j]) < EPSILON)
                            continue; //防止分母为0
                        list2.push_back(list[i] / list[j]);
                    }
                    //探索子问题
                    if (solve(list2))
                        return true;
                    list2.pop_back(); //回溯法，探索完子问题后要恢复原样
                }
            }
        }
    }
    return false;
}

bool judgePoint24(vector<int> &nums)
{
    vector<double> list;
    for (auto a : nums)
        list.push_back(a);
    return solve(list);
}

int main(){
    vector<int> nums={4,1,8,7};
    bool res = judgePoint24(nums);
    if(res) cout<<"true"<<endl;
    else cout<<"false"<<endl;
}