#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
    friend std::ostream &print(std::ostream &, const Person &);
	friend std::istream &read(std::istream &, Person &);
    Person()=default;
    Person(const std::string newname, const std::string newaddress):name(newname), address(newaddress){}
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }

private:
    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &person){
    is>>person.name>>person.address;
    return is;
}
std::ostream &print(std::ostream &os, const Person &person){
    os<<person.name<<"  "<<person.address;
    return os;
}
#endif