#include <list>
#include <iostream>
#include <iterator>

// int LastRemaining_Solution(int n, int m)
// {
//     if (n < 1 || m < 1)
//         return -1;
//     std::list<int> arr;
//     for (int i = 0; i < n; ++i)
//     {
//         arr.push_back(i);
//     }
//     std::list<int>::iterator current = arr.begin();
//     while (arr.size() > 1)
//     {
//         for (int i = 1; i < m; ++i)
//         {
//             current++;
//             if (current == arr.end())
//                 current = arr.begin();
//         }
//         std::list<int>::iterator next = ++current;
//         if (next == arr.end())
//             next = arr.begin();
//         --current;
//         arr.erase(current);
//         current = next;
//     }
//     return *(current);
// }

int LastRemaining_Solution(int n, int m)
{
}
int main()
{
    std::cout << "result:  " << LastRemaining_Solution(5, 3) << std::endl;
    return 0;
}