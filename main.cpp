#include "management.hpp"

int main()
{

    bool repeat = false;
    message("HOTEL RESERVATION SYSTEM");
    message(Hotel);
start:
    try {
        TerminalInteract();
    } catch (const HotelException& e) {
        message(e.get_msg());
        repeat = true;
    }

    clean();
    if (repeat) {
        repeat = false;
        goto start;
    }
    message("program is exited correctly");
    return 0;
}
