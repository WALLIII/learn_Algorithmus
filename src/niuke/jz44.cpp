#include <string>
#include <iostream>
void ReverseWord(std::string &str, int s, int e)
{
    while (s < e)
    {
        std::swap(str[s], str[e]);
        s++;
        e--;
    }
}

std::string ReverseSentence(std::string str)
{
    if (str.size() <= 1)
        return str;
    ReverseWord(str, 0, str.size() - 1);

    int s = 0, e = 0, i = 0;
    while (i < str.size())
    {
        while (i < str.size() && str[i] == ' ')
        {
            ++i;
        }
        e = s = i;
        while (i < str.size() && str[i] != ' ')
        {
            ++i;
            ++e;
        }
        ReverseWord(str, s, e - 1);
    }
    return str;
}

int main()
{
    std::string str = "I am a student.";
    std::string str2;
    str2 = ReverseSentence(str);
    std::cout << str2 << std::endl;
    return 0;
}