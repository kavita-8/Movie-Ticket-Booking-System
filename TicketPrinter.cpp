#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class TicketPrinter {
public:
    static void print(const Booking& booking) {
        Show* show = booking.getShow();

        cout << "\n========================================\n";
        cout << "             MOVIE TICKET\n";
        cout << "========================================\n";
        cout << "Booking ID : " << booking.getBookingId() << '\n';
        cout << "Customer   : " << booking.getCustomer().getName() << '\n';
        cout << "Phone      : " << booking.getCustomer().getPhone() << '\n';
        cout << "Movie      : " << show->getMovie()->getTitle() << '\n';
        cout << "Language   : " << show->getMovie()->getLanguage() << '\n';
        cout << "Screen     : " << show->getScreen()->getScreenNumber() << '\n';
        cout << "Time       : " << show->getStartTime() << '\n';
        cout << "Seats      : ";

        for (size_t i = 0; i < booking.getSeats().size(); ++i) {
            ShowSeat* ss = booking.getSeats()[i];
            cout << ss->getSeat()->getSeatNumber()
                 << " (" << Seat::typeName(ss->getSeat()->getType()) << ")";
            if (i + 1 < booking.getSeats().size()) cout << ", ";
        }

        cout << '\n';
        cout << "Payment    : " << booking.getPayment()->methodName() << '\n';
        cout << fixed << setprecision(2);
        cout << "Total      : Rs. " << booking.getTotalAmount() << '\n';
        cout << "Status     : "
             << (booking.getStatus() == BookingStatus::CONFIRMED
                 ? "CONFIRMED" : "CANCELLED") << '\n';
        cout << "========================================\n";
    }
};
