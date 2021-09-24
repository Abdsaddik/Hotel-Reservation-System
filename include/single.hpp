#ifndef SINGLE_HPP
#define SINGLE_HPP

#include "accomodation.hpp"

class Single : public Accomodation {
private:
    static double price;

public:
    Single(Date date,
        Customer* customer,
        Room* room,
        bool garage = false,
        Order* order = NULL);
    virtual double get_price() const;
    virtual void print() const;
};
#endif
