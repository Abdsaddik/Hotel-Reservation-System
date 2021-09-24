#ifndef HOTELEXCEPTION
#define HOTELEXCEPTION

class HotelException {
private:
    const char* msg;
    HotelException() = delete;

public:
    explicit HotelException(const char* str)
        : msg{ str }
    {
    }
    const char* get_msg() const { return msg; }
};

#endif
