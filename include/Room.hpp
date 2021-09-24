#ifndef ROOM_HPP
#define ROOM_HPP
#include <stdint.h>
class Room {
private:
    uint32_t no; // room number
    uint32_t beds; // beds numbers
    bool balcony;

public:
    Room(uint32_t no, uint32_t beds, bool balcony);
    uint32_t get_beds() const;
    uint32_t get_room_no() const;
    void print() const;
    ~Room();
};

#endif