#include "Room.hpp"
#include <iostream>

Room::Room(uint32_t no, uint32_t beds, bool balcony)
    : no{ no }
    , beds{ beds }
    , balcony{ balcony }
{
}

uint32_t Room::get_beds() const
{
    return beds;
}

uint32_t Room::get_room_no() const
{
    return no;
}

void Room::print() const
{
    std::cout << "room no. : " << no << ", " << beds << " bed(s)";
    if (balcony)
        std::cout << ", balcony";
}

Room::~Room()
{
}
