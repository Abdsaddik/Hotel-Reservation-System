#ifndef ORDER_HPP
#define ORDER_HPP

// #include"global_defs.hpp"
#include "Bill.hpp"
#include "Customer.hpp"
#include "Date.hpp"
#include "Room.hpp"

class Order {
private:
    Date bookedFor;
    Bill* bill;
    Customer* customer;
    Order* next;

public:
    Order(Date date, Customer* customer, Order* order = NULL);
    Date get_bookedFor() const;
    Customer* get_customer();
    void set_next(Order* next);
    Order* get_next() const;
    bool invoiced() const;
    void set_bill(Bill* bill);
    virtual Room* get_room() const;
    virtual double get_price() const = 0;
    virtual void print() const = 0;
    virtual ~Order() {}
};

#endif