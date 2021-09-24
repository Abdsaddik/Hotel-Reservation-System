#ifndef BREAKFAST_HPP
#define BREAKFAST_HPP

#include "Date.hpp"
#include "Order.hpp"
#include <iomanip>

class Breakfast : public Order {
private:
    static double price;

public:
    Breakfast(Date date, Customer* customer, Order* order = NULL)
        : Order(date, customer, order)
    {
    }
    virtual double get_price() const;
    virtual void print() const;
};

#endif
