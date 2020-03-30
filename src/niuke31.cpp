#include <vector>
#include <stack>
#include <iostream>

// bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV)
// {
//     int pushLength = pushV.size();
//     int popLength = popV.size();
//     if (pushLength == 0 || popLength == 0)
//         return false;
//     std::stack<int> s;
//     s.push(pushV[0]);
//     int pushIndex = 1;
//     int popIndex = 0;
//     while (!s.empty())
//     {
//         if (s.top() == popV[popIndex])
//         {
//             popIndex++;
//             s.pop();
//         }
//         else if (s.top() != popV[popIndex] && pushIndex < pushLength)
//         {
//             s.push(pushV[pushIndex]);
//             pushIndex++;
//         }
//         else if (s.top() != popV[popIndex] && pushIndex == pushLength)
//         {
//             s.pop();
//         }
//         if (popIndex == popLength)
//             return true;
//     }
//     return false;
// }

bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV)
{

    if (pushV.size() == 0)
         return false;
    std::vector<int> stack;
    for (int i = 0, j = 0; i < pushV.size();)
    {
        stack.push_back(pushV[i++]);
        while (j < popV.size() && stack.back() == popV[j])
        {
            stack.pop_back();
            j++;
        }
    }
    return stack.empty();
}

int main()
{
    std::vector<int> push = {1, 2, 3, 4, 5};
    std::vector<int> pop = {4, 5, 3, 1,2};
    if (IsPopOrder(push, pop))
    {
        std::cout << "pop series is pop order of push series!" << std::endl;
    }
    else
    {
        std::cout << "no..." << std::endl;
    }
    return 0;
}