#ifndef Customer_HPP
#define Customer_HPP

#include <iostream>

class Customer {
private:
    std::string name;
    std::string phone;
    Customer* next = nullptr;

public:
    Customer(std::string name, std::string phone = "", Customer* next = nullptr);
    std::string get_name() const;
    Customer* get_next() const;
    void set_next(Customer* next);
    friend std::ostream& operator<<(std::ostream& out, Customer& c);
    ~Customer();
};
#endif
