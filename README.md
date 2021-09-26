# Hotel-Reservation-System
## Overview
Hotel Reservation System written in C++. This program can be used in terminal for the time of writing this README file, it has no Graphical User Interface. It handels several situations of booking such as a single room, double room, reservation with a breakfast/without breakfast, with Garage reservation/without Garage reservation and other options.
## Terminal Output
An optimal terminal output for the program should be as follows:  
```
HOTEL RESERVATION SYSTEM
Duisburg Happy Sleeping
e   end
n   new customer
p   print all customers
a   accomodation booking
b   breakfast booking
s   show all orders
d   delete a customer
your choice:   
```
How to use the program is self explained by following the terminal output.
## Workflow
- Clone the repo from https or ssh as follows  
```git clone https://github.com/Abdsaddik/Hotel-Reservation-System.git```
- Go inside the cloned project directory  
```cd Hotel-Reservation-System/```
- Create build directory and use cmake to copmile the project  
```cd build && cmake ..```
- Compile the project with **make** command inside the build directory  
```make```
- Run the program  
```./HoteslSys```
## Notice
I did not publish all source files. Instead I added an object file. As a result,  this project may not be used with normal users as the program limits the support for only 4 rooms.