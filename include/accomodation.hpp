#ifndef ACCOMODATION
#define ACCOMODATION

#include "Order.hpp"
#include "Room.hpp"

class Accomodation : public Order {
private:
    bool garage;
    Room* room;
    static double priceParking;

public:
    Accomodation(Date date,
        Customer* customer,
        Room* room,
        bool garage = false,
        Order* order = NULL);
    double priceForParking() const;
    Room* get_room() const;
    virtual void print() const;
    virtual ~Accomodation() { delete room; }
};

#endif
