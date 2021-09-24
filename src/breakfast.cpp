#include "breakfast.hpp"

double Breakfast::price = 9.9;

double Breakfast::get_price() const
{
    return price;
}

void Breakfast::print() const
{
    std::cout << std::setprecision(2) << get_bookedFor() << '\t' << get_price() << " EUR: Breakfast\n";
}