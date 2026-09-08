MOVIE TICKET BOOKING SYSTEM - C++17

This is a console-based System Design project for a single cinema.

FEATURES
1. List movies
2. View shows and timings
3. View available/booked seats
4. Book one or more seats
5. Seat pricing:
   Silver   = Rs. 150
   Gold     = Rs. 250
   Platinum = Rs. 400
6. Payment through UPI, Card, or Cash
7. Print ticket
8. Cancel booking and release seats
9. List all bookings
10. Failed payment does not confirm the booking

PROJECT FILES
Movie.cpp
Seat.cpp
Screen.cpp
Cinema.cpp
Show.cpp
ShowSeat.cpp
Customer.cpp
Booking.cpp
Payment.cpp
UpiPayment.cpp
CardPayment.cpp
CashPayment.cpp
PriceCalculator.cpp
TicketPrinter.cpp
BookingService.cpp
main.cpp

REQUIREMENTS
- C++ compiler supporting C++17
- g++ / MinGW on Windows

COMPILE
Open Command Prompt in this folder and run:

g++ -std=c++17 main.cpp -o MovieTicketBooking.exe

RUN
MovieTicketBooking.exe

IMPORTANT
main.cpp includes the individual class .cpp files so the project can be
compiled using one simple command without separate header files.
