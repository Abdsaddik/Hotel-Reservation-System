#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "accomodation.hpp"

class Double : public Accomodation {
private:
    double static price;

public:
    Double(Date date,
        Customer* customer,
        Room* room,
        bool garage = false,
        Order* order = NULL);
    virtual double get_price() const;
    virtual void print() const;
};

#endif