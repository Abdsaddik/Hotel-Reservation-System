#ifndef Date_HPP
#define Date_HPP

#include "HotelException.hpp"
#include <iostream>
#include <regex>

const std::regex date_expr("^\\s*[0-9]{2}\\s*.\\s*[0-9]{2}\\s*.\\s*(19|20)[0-9]{2}\\s*$");

class Date {
private:
    std::string day_;
    std::string month_;
    std::string year_;
    static const int monthDays[];

public:
    Date(std::string day = "09", std::string month = "01", std::string year = "2015");
    friend std::istream& operator>>(std::istream& i, Date& d);
    friend std::ostream& operator<<(std::ostream& o, const Date& d);
    friend bool operator==(const Date& d1, const Date& d2);
    ~Date();
};

#endif
