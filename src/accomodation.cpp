#include "accomodation.hpp"

double Accomodation::priceParking = 15.0;

Accomodation::Accomodation(Date date,
    Customer* customer,
    Room* room,
    bool garage,
    Order* order)
    : Order{ date, customer, order }
    , garage{ garage }
    , room{ room }
{
}

double Accomodation::priceForParking() const
{
    if (garage)
        return priceParking;
    return 0.0;
}

Room* Accomodation::get_room() const
{
    return room;
}

void Accomodation::print() const
{
    std::cout << get_bookedFor() << '\t' << get_price() << " EUR, ";
    room->print();
    if (garage)
        std::cout << ", garage";
}