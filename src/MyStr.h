#ifndef _MY_STR_H
#define _MY_STR_H
#include <iostream>

class Mystring
{
    friend std::ostream &operator<<(std::ostream &out, const Mystring &obj);
    friend std::istream &operator>>(std::istream &in, Mystring &obj);

public:
    Mystring();                       //默认构造函数
    Mystring(const char *str = NULL); //构造函数
    Mystring(const Mystring &obj);
    // 操作符重载
    Mystring operator=(const Mystring &obj);
    Mystring operator+(const Mystring &obj);
    Mystring operator+=(const Mystring &obj);
    bool operator!=(const Mystring &obj);
    bool operator==(const Mystring &obj);
    bool operator>(const Mystring &obj);
    bool operator<(const Mystring &obj);

    ~Mystring()
    {
        delete[] pstr;
        pstr = NULL;
    }

private:
    char *pstr;
};
// 构造函数
Mystring::Mystring(const char *str)
{
    if (str == NULL)
    {
        pstr = new char[1];
    }
    else
    {
        pstr = new char[strlen(str) + 1];
        strcpy(pstr, str);
    }
}

// 拷贝构造函数
Mystring::Mystring(const Mystring &obj)
{
    pstr = new char[strlen(obj.pstr) + 1];
    strcpy(pstr, obj.pstr);
}

Mystring Mystring::operator=(const Mystring &obj)
{
    if (pstr != NULL)
        delete[] pstr;
    strcpy(pstr, obj.pstr);
    return *this;
}

Mystring Mystring::operator+=(const Mystring &obj)
{
    char *temp = pstr;
    pstr = new char[strlen(temp) + strlen(obj.pstr) + 1];
    strcpy(pstr, temp); //先把原来的内容拷回pstr，再在后面加上新的
    delete[] temp;
    strcat(pstr, obj.pstr);
    return *this;
}

Mystring Mystring::operator+(const Mystring &obj)
{
    Mystring newstring("");
    newstring.pstr = new char[strlen(pstr) + strlen(obj.pstr) + 1];
    strcat(newstring.pstr, pstr);
    strcat(newstring.pstr, obj.pstr);
    return newstring;
}

bool Mystring::operator!=(const Mystring &obj)
{
    if (strcmp(pstr, obj.pstr) == 0)
        return false;
    else
        return true;
}

bool Mystring::operator==(const Mystring &obj)
{
    if (strcmp(pstr, obj.pstr) == 0)
        return true;
    else
        return false;
}

bool Mystring::operator>(const Mystring &obj)
{
    if (strcmp(pstr, obj.pstr) > 0)
        return true;
    else
        return false;
}

bool Mystring::operator<(const Mystring &obj)
{
    if (strcmp(pstr, obj.pstr) < 0)
        return true;
    else
        return false;
}

std::ostream &operator<<(std::ostream &out, const Mystring &obj)
{
    std::cout << obj.pstr;
    return out;
}

std::istream &operator>>(std::istream &in, Mystring &obj)
{
    obj.pstr = new char[1024];
    in >> obj.pstr;
    return in;
}

#endif //_MY_STR_H