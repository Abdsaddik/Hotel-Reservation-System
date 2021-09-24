#ifndef MANAGEMENT_HPP
#define MANAGEMENT_HPP

#include "Customer.hpp"
#include "breakfast.hpp"
#include "double.hpp"
#include "global_defs.hpp"
#include "single.hpp"

template <typename T>
void message(T s);

template <typename T1, typename T2>
void message(T1 s, T2 val);

template <typename T>
void shortMsg(T s);

std::string readTerminal(std::string& s);

uint16_t searchFreeRoom(Date& date, uint16_t beds, Order* firstOrder);

void fillRooms();

void printAllRooms();

void deleteAllRooms();

void deletAllOrders();

void insertCustomer(Customer** first, Customer** cstmr, std::string name, std::string phone);

void addCustomer(Customer** first, Customer** cstmr, std::string name, std::string phone);

bool searchCustomer(Customer* customer, std::string name);

void deleteAllCustomers();

void printCustomers(Customer* customer);

// this is a generic function to read the val a or b regarding regex pattern, for example; b with breakfast and w without brekfast
// in this case only the letters (b/B, w/W) are accepted
uint8_t checkInput(std::string& s, char a, char b);

// list and print orders on the terminal
void listOrders(Order* order);

// insert an order to order list
template <typename T>
void insertOrder(Order** firstOrder, Date date, Room* room, bool garage);

// insert a breakfast order
void insertBreakfast(Date date, uint16_t count = 1);

void checkRgx(std::string rgxPatrn, std::string& input, std::string msg = "invalid input");

void TerminalInteract();

void clean();

#endif
