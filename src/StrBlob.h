#ifndef _STR_BLOB_H
#define _STR_BLOB_H
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob() :data(std::make_shared<std::vector<std::string>>()){};                                                                                               //默认构造函数
    StrBlob(std::initializer_list<std::string> i1) : data(std::make_shared<std::vector<std::string>>(i1)){}; //可以接受花括号列表初始化string
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    std::string &front();
    std::string &back();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

void StrBlob::check(size_type i, const std::string &msg) const{
    if(i>=data->size()){
        throw std::out_of_range(msg);
    }
}
std::string &StrBlob::front(){
    check(0, "front on empty blob");
    return data->front();
}
#endif //_STR_BLOB_H