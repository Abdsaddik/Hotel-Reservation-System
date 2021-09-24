#include "single.hpp"

double Single::price = 49.00;

Single::Single(Date date,
    Customer* customer,
    Room* room,
    bool garage,
    Order* order)
    : Accomodation{ date, customer, room, garage, order }
{
}

double Single::get_price() const
{
    return (priceForParking() > 0) ? (price + Accomodation::priceForParking()) : price;
}

void Single::print() const
{
    Accomodation::print();
    std::cout << " (as single)" << std::endl;
}
