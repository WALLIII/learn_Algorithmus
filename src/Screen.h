#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <iostream>
#include <vector>
class Screen;

class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    inline void clear(ScreenIndex);

private:
    std::vector<Screen> screens;
};

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default; //显示地声明，需要编译器合成一个构造函数
    //cursor成员隐式的使用了类内初始值，如果cursor没有类内初始值，就需要显示的初始化了
    Screen(pos ht, pos wd) : height(ht), width(wd), contents("") {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; } //读取光标处的字符
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    void some_member() const { ++access_ctr; }
    Screen &set(char c)
    {
        contents[cursor] = c; //当前光标位置设置新值
        return *this;
    }
    Screen &set(pos r, pos col, char c)
    {
        contents[r * width + col] = c;
        return *this;
    }
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;
    void do_display(std::ostream &os) const { os << contents; }
};

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c; //在行内吧光标移动到指定位置
    return *this;
}
char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

#endif