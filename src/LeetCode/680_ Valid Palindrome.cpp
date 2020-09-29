#include <string>
#include <iostream>
using namespace std;
bool helper(string &s, int b, int e)
{
    if (b == e)
        return true;
    while (b < e)
    {
        if (s[b] != s[e])
            return false;
        ++b;
        --e;
    }
    return true;
}
bool validPalindrome(string s)
{
    if (s.empty())
        return true;
    int p1 = 0, p2 = s.size() - 1;
    bool count = false;
    while (p1 < p2)
    {
        if (s[p1] == s[p2])
        {
            ++p1;
            --p2;
        }
        else if (s[p1] != s[p2])
        {
            return helper(s, p1 + 1, p2) || helper(s, p1, p2 - 1);
        }
    }
    return true;
}

int main()
{
    string s = "ebcbbececabbacecbbcbe";
    cout << validPalindrome(s) << endl;
}