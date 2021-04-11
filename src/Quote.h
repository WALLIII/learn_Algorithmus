#ifndef _QUOTE_H
#define _QUOTE_H
#include <iostream>
#include <string>
#include <fstream>
class Quote
{
public:
    Quote() { std::cout << "default Quote quote" << std::endl; } //默认构造
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) { std::cout << "Quote quote" << std::endl; }
    std::string isbn() const { return bookNo; }                         //返回书的isbn号
    virtual double net_price(std::size_t n) const { return n * price; } //这里父类返回原价
    virtual void debug() const
    {
        std::cout << "member of this class:" << std::endl
                  << "isbn: " << this->isbn() << " price: " << this->price << std::endl;
    }
    virtual ~Quote() { std::cout << "~Quote quote" << std::endl; };

protected:
    std::string bookNo;

protected:
    double price;
};
//打印销售给定数目某种书所得营业额
class Disc_quote : public Quote
{
public:
    Disc_quote() { std::cout << "default Disc quote" << std::endl; }
    Disc_quote(const std::string &s, double p, double disc, std::size_t quan) : Quote(s, p), discount(disc), quantity(quan) { std::cout << "Disc quote" << std::endl; }
    double net_price(std::size_t n) const = 0;
    ~Disc_quote() { std::cout << "~Disc quote" << std::endl; }

protected:
    double discount = 0.0;
    std::size_t quantity = 0;
};
class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() { std::cout << "default Bulk quote" << std::endl; }
    Bulk_quote(const std::string &s, double p, std::size_t qty, double dis) : Disc_quote(s, p, dis, qty) { std::cout << "Bulk quote" << std::endl; } //只能初始化直接基类
    double net_price(std::size_t n) const override;
    void debug() const
    {
        std::cout << "member of this class:" << std::endl
                  << "isbn: " << isbn() << " price: " << this->price
                  << " discount: " << this->discount << " min_qty: " << this->quantity << std::endl;
    }

    ~Bulk_quote() { std::cout << "~Bulk quote" << std::endl; }
};

double Bulk_quote::net_price(std::size_t n) const
{
    if (n >= quantity)
    {
        return n * (1 - discount) * price;
    }
    else
        return n * price;
}
#endif //_QUOTE_H