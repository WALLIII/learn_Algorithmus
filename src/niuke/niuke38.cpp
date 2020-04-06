#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// recursively
// void swap(char &c1, char &c2)
// {
//     char tmp = c1;
//     c1 = c2;
//     c2 = tmp;
// }
// void Permutation(std::string str, std::vector<std::string> &res, int begin)
// {
//     if (begin == str.size() - 1)
//     {
//         if (std::find(res.begin(), res.end(), str) == res.end())
//         {
//             res.push_back(str);
//         }
//     }
//     else
//     {
//         for (int i = begin; i < str.size(); ++i)
//         {
//             swap(str[i], str[begin]);
//             Permutation(str, res, begin + 1);
//             swap(str[i], str[begin]);
//         }
//     }
// }

// std::vector<std::string> Permutation(std::string str)
// {
//     std::vector<std::string> res;
//     if (str.empty())
//     {
//         return res;
//     }
//     Permutation(str, res, 0);
//     std::sort(res.begin(), res.end());
//     return res;
// }

std::vector<std::string> Permutation(std::string str)
{
    std::vector<std::string> res;
    int len = str.length();
    if (len == 0)
    {
        return res;
    }
    else if (len == 1)
    {
        res.push_back(str);
        return res;
    }
    std::vector<char> char_list;
    int i, j;
    for (i = 0; i < len; i++)
    {
        char_list.push_back(str[i]);
    }
    std::sort(char_list.begin(), char_list.end());
    for (i = 0; i < len; i++)
    {
        str[i] = char_list[i];
    }
    res.push_back(str);
    int left, right;
    char min_one;
    while (true)
    {
        left = -1;
        for (j = len - 1; j >= 1; j--)
        {
            if (str[j - 1] < str[j])
            {
                left = j - 1;
                break;
            }
        }

        if (left == -1)
        {
            break;
        }
        min_one = str[left + 1];
        right = left + 1;
        for (j = left + 2; j < len; j++)
        {
            if (str[j] > str[left] && str[j] < min_one)
            {
                min_one = str[j];
                right = j;
            }
        }
        swap(str[left], str[right]);
        for (i = left + 1, j = len - 1; i < j; i++, j--)
        {
            swap(str[i], str[j]);
        }
        res.push_back(str);
    }

    return res;
}

int main()
{
    std::vector<std::string> res;
    std::string str = "abc";
    res = Permutation(str);
    for (auto st : res)
    {
        std::cout << st << std::endl;
    }
    // std::string str="123456";
    // std::cout<<str<<std::endl;
    return 0;
}