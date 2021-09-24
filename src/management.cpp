#include "management.hpp"

Room** rooms = nullptr;
Customer* customers = nullptr;
Order* orders = NULL;

template <typename T>
void message(T s)
{
    std::cout << s << std::endl;
}

template <typename T1, typename T2>
void message(T1 s, T2 val)
{
    std::cout << s << " = " << val << std::endl;
}

template <typename T>
void shortMsg(T s)
{
    std::cout << s;
}

std::string readTerminal(std::string& s)
{
    std::getline(std::cin, s, '\n');
    return s;
}

uint16_t searchFreeRoom(Date& date, uint16_t beds, Order* firstOrder)
{
    uint16_t cnt = (beds == 1) ? 0 : 2;
    uint16_t maxNum = (cnt == 0) ? numberOfRooms / 2 : numberOfRooms;
    Order* first = firstOrder;
    while ((firstOrder) != NULL) {
        if ((firstOrder)->get_room() != NULL && (firstOrder)->get_room()->get_beds() == beds && (firstOrder)->get_bookedFor() == date) {
            cnt++;
            (firstOrder) = (firstOrder)->get_next();
            continue;
        }
        (firstOrder) = (firstOrder)->get_next();
    }
    firstOrder = first;
    if ((cnt + 1) > maxNum) {
        throw HotelException("all rooms are reserved");
    }
    return cnt;
}

void fillRooms()
{
    rooms = new Room*[numberOfRooms];
    for (uint32_t cnt = 0; cnt < (numberOfRooms / 2); cnt++) {
        rooms[cnt] = new Room{ cnt, 1, false };
        rooms[cnt + 2] = new Room{ cnt + 2, 2, true };
    }
}

void printAllRooms()
{
    message(Hotel);
    for (uint32_t cnt = 0; cnt < numberOfRooms; cnt++) {
        rooms[cnt]->print();
        std::cout << std::endl;
    }
}

void deleteAllRooms()
{
    for (uint32_t cnt = 0; cnt < numberOfRooms; cnt++) {
        if (rooms[cnt] != nullptr)
            delete rooms[cnt];
    }
    if (rooms != nullptr)
        delete[] rooms;
}

void deletAllOrders()
{
    Order* tmp = orders;
    while (orders != nullptr) {
        tmp = orders->get_next();
        delete orders;
        orders = nullptr;
        orders = tmp;
    }
}

void insertCustomer(Customer** first, Customer** cstmr, std::string name, std::string phone)
{
    if (!cstmr[0]) {
        message("index zero");
        first[0] = new Customer{ name, phone };
        cstmr[0] = first[0];
    } else {
        message("another index");
        cstmr[0]->set_next(new Customer{ name, phone });
        cstmr[0] = cstmr[0]->get_next();
    }
    cstmr[0]->set_next(nullptr);
}

inline void checkRgx(std::string rgxPatrn, std::string& input, std::string msg)
{
    while (!std::regex_match(readTerminal(input), std::regex(rgxPatrn))) {
        message(std::string(msg));
        shortMsg("input:   ");
    }
}

void addCustomer(Customer** first, Customer** cstmr, std::string name, std::string phone)
{
    std::string nameRgx = "^\\s*?[a-z A-Z]*$";
    std::string phoneRgx = "^\\s*[0-9 +-]*$";
    message("add a new customer");
    shortMsg("name:   ");
    checkRgx(nameRgx, name, "invalid input! ,  only alphabetic letters are allowed");
    shortMsg("phone:   ");
    checkRgx(phoneRgx, phone, "invalid input! ,  only numbers are allowed");
    insertCustomer(first, cstmr, name, phone);
}

bool searchCustomer(Customer* customer, std::string name)
{
    Customer* cstmr = customer;
    while (cstmr != NULL) {
        if (cstmr->get_name() == name) {
            message("customer found");
            return true;
        }
        cstmr = cstmr->get_next();
    }
    return false;
}

bool deleteCustomer(Customer** firtCstmr, std::string name)
{
    Customer *cstmr = *firtCstmr, *tmp = nullptr;
    uint16_t cnt = 0;
    while (cstmr != NULL) {
        if (cstmr->get_name() == name && cnt == 0) {
            tmp = cstmr;
            cstmr = cstmr->get_next();
            delete tmp;
            tmp = nullptr;
            *firtCstmr = cstmr;
            customers = cstmr;
            shortMsg("Customer: ");
            message(*firtCstmr);
            return true;
        } else if (cstmr->get_name() == name && cnt == 1) {
            tmp = cstmr;
            (*firtCstmr)->set_next(tmp->get_next());
            delete tmp;
            tmp = nullptr;
            return true;
        } else if (cstmr->get_name() == name && cnt > 1) {
            cstmr = *firtCstmr;
            for (int count = 0; count <= (cnt - 2); count++) {
                cstmr = cstmr->get_next();
            }
            tmp = cstmr->get_next();
            cstmr->set_next(tmp->get_next());
            delete tmp;
            tmp = nullptr;
            customers = cstmr;
            return true;
        }
        cstmr = cstmr->get_next();

        cnt++;
    }
    return false;
}

void deleteAllCustomers()
{
    Customer* tmp = nullptr;
    while (customers != nullptr) {
        tmp = customers->get_next();
        delete customers;
        customers = nullptr;
        customers = tmp;
    }
    message("all customers are deleted");
}

void printCustomers(Customer* customer)
{
    if (customer == nullptr) {
        message("customer list is empty");
        return;
    }
    message("list of CUSTOMERS");
    Customer* cstmr = customer;
    while (cstmr != NULL) {
        message(*cstmr);
        cstmr = cstmr->get_next();
    }
}

uint8_t checkInput(std::string& s, char a, char b)
{
    // "^\\s*[a|A|b|B]\\s*$"
    readTerminal(s);
    std::string rgxPtrn = std::string("^\\s*[") + (char)a + (char)'|' + (char)std::toupper(a)
        + (char)'|' + (char)b + (char)'|' + (char)std::toupper(a) + std::string("]\\s*$");
    // accept only a specific input data a or A or b or B
    while (!std::regex_match(s, std::regex(rgxPtrn))) {
        shortMsg(std::string("invalid input! ,  please choose ") + (char)a + std::string(" or ") + (char)b + std::string(":   "));
        readTerminal(s);
    }
    return s[0];
}

void listOrders(Order* order)
{
    message("list orders");
    Order* first = order;
    if (order == nullptr) {
        message("there is no orders");
        return;
    }
    while (order != nullptr) {
        order->print();
        order = order->get_next();
    }
    order = first;
}

template <typename T>
void insertOrder(Order** firstOrder, Date date, Room* room, bool garage)
{
    if (orders == nullptr) {
        *firstOrder = new T{ date, customers, room, garage };
        orders = *firstOrder;
    } else {
        orders->set_next(new T{ date, customers, room, garage });
        orders = orders->get_next();
    }
    orders->set_next(nullptr);
}

void insertBreakfast(Date date, uint16_t count)
{
    for (uint16_t cnt = 0; cnt < count; cnt++) {
        orders->set_next(new Breakfast{ date, customers });
        orders = orders->get_next();
        orders->set_next(nullptr);
    }
}

void TerminalInteract()
{
    std::string input, name, phone;
    uint32_t roomTyp;

    Order* firstOrder = nullptr;
    bool breakfast = false, garage = false;
    Date date;
    Customer* first = nullptr;

    fillRooms();

    while (true) {
        shortMsg("e   end\n"
                 "n   new customer\n"
                 "p   print all customers\n"
                 "a   accomodation booking\n"
                 "b   breakfast booking\n"
                 "s   show all orders\n"
                 "d   delete a customer\n"
                 "your choice:   ");
        readTerminal(input);
        switch (input[0]) {
        case 'a':
            shortMsg("for which customer name: ");
            readTerminal(input);
            if (!searchCustomer(first, input))
                throw HotelException("sorry customer not found");
            std::cin >> date;
            shortMsg("d for double room, s for single room:   ");
            roomTyp = checkInput(input, 'd', 's');
            shortMsg("b for breakfast , w without breakfast:   ");
            // set the flag breakfast according to the user choise
            if (checkInput(input, 'b', 'w') == 'b')
                breakfast = true;
            else
                breakfast = false;
            shortMsg("g for garage , w without garage:   ");
            // set the flag breakfast according to the user choise
            if (checkInput(input, 'g', 'w') == 'g')
                garage = true;
            else
                garage = false;
            roomTyp = (roomTyp == 'd' || roomTyp == 'D') ? 2 : 1;
            // insert a single object
            if (roomTyp == 1)
                insertOrder<Single>(&firstOrder, date, rooms[searchFreeRoom(date, roomTyp, firstOrder)], garage);
            // insert a double object
            else if (roomTyp == 2)
                insertOrder<Double>(&firstOrder, date, rooms[searchFreeRoom(date, roomTyp, firstOrder)], garage);
            if (roomTyp == 1 && breakfast == true)
                insertBreakfast(date);
            if (roomTyp == 2 && breakfast == true)
                insertBreakfast(date, 2);
            break;

        case 'e':
        case 'E':
            message("exit the program");
            orders = firstOrder;
            return;
            break;

        case 'n':
        case 'N':
            addCustomer(&first, &customers, name, phone);
            break;

        case 'p':
        case 'P':
            printCustomers(first);
            break;

        case 's':
        case 'S':
            listOrders(firstOrder);
            break;

        case 'd':
        case 'D':
            shortMsg("insert name of Customer to be removed:   ");
            name = "";
            readTerminal(name);
            if (!searchCustomer(first, name))
                throw HotelException("sorry customer not found");
            if (deleteCustomer(&first, name))
                message("Customer " + name + " is deleted");
            else
                message("customer is not deleted");
            break;

        case 0:
            message("nothing is selected!");
            break;
        default:
            message("unknown choice!");
            break;
        }
    }
}

void clean()
{
    deleteAllRooms();
    deleteAllCustomers();
    deletAllOrders();
}
