#include "double.hpp"

double Double::price = 69;

Double::Double(Date date,
    Customer* customer,
    Room* room,
    bool garage,
    Order* order)
    : Accomodation{ date, customer, room, garage, order }
{
    if (room->get_beds() < 2)
        std::cout << "additional bed required" << std::endl;
}

double Double::get_price() const
{
    return (priceForParking() > 0) ? (price + Accomodation::priceForParking()) : price;
}

void Double::print() const
{
    Accomodation::print();
    std::cout << " (as double)" << std::endl;
}
