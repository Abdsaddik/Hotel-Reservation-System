#include "Order.hpp"

Order::Order(Date date, Customer* customer, Order* order)
    : bookedFor{ date }
    , customer{ customer }
    , next{ order }
{
}

Date Order::get_bookedFor() const
{
    return bookedFor;
}

Customer* Order::get_customer()
{
    return customer;
}

void Order::set_next(Order* next)
{
    this->next = next;
}

Order* Order::get_next() const
{
    return next;
}

bool Order::invoiced() const
{
    if (bill == NULL)
        return NULL;
    return true;
}

void Order::set_bill(Bill* bill)
{
    this->bill = bill;
}

Room* Order::get_room() const
{
    return NULL;
}
