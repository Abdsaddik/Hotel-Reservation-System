#include "Date.hpp"

constexpr int Date::monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(std::string day, std::string month, std::string year)
    : day_{ day }
    , month_{ month }
    , year_{ year }
{
}

std::istream& operator>>(std::istream& i, Date& d)
{
    std::string date;
    while (true) {
        std::cout << "for which date (enter birth in format DD.MM.YYYY): ";
        std::getline(std::cin, date, '\n');
        if (std::regex_match(date, date_expr)) {
            std::remove(date.begin(), date.end(), ' ');
            d.day_ = date.substr(0, 2);
            d.month_ = date.substr(3, 2);
            d.year_ = date.substr(6, 4);
            break;
        } else if (date.size() == 0)
            return i;
        else {
            std::cout << "invalid input\n";
        }
    }
    return i;
}

std::ostream& operator<<(std::ostream& o, const Date& d)
{
    return o << d.day_ + '.' + d.month_ + '.' + d.year_;
}

bool operator==(const Date& d1, const Date& d2)
{
    return (d1.day_ == d2.day_) && (d1.month_ == d1.month_) && (d2.year_ == d2.year_);
}

Date::~Date()
{
}
