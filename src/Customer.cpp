#include "Customer.hpp"

Customer::Customer(std::string name, std::string phone, Customer* next)
    : name{ name }
    , phone{ phone }
    , next{ next }
{
}

std::string Customer::get_name() const
{
    return name;
}
Customer* Customer::get_next() const
{
    return next;
}

void Customer::set_next(Customer* next)
{
    this->next = next;
}

std::ostream& operator<<(std::ostream& out, Customer& c)
{
    out << "name of customer: " << c.name;
    if (!c.phone.empty())
        out << " , phone: " << c.phone;
    return out;
}

Customer::~Customer()
{
}
