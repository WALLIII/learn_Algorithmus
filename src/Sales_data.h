#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>
#include <fstream>

class Sales_data
{
	friend Sales_data add(const Sales_data &, const Sales_data &);
	friend std::ostream &print(std::ostream &, const Sales_data &);
	friend std::istream &read(std::istream &, Sales_data &);

public:
	// constructors
	Sales_data() : units_sold(0), revenue(0.0) {}
	Sales_data(const std::string &s) : bookNo(s), units_sold(0), revenue(0.0) {}
	Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
	Sales_data(std::istream &);
	Sales_data(std::string s):Sales_data(s, 0, 0){} //委托构造函数

	// operations on Sales_data objects
	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &);

private:
	double avg_price() const { return units_sold ? revenue / units_sold : 0; };
	std::string bookNo;
	unsigned units_sold=0;
	double revenue=0.0;
};
#endif
