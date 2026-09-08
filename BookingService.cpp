#pragma once
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class BookingService {
private:
    vector<Booking*> bookings;

public:
    ~BookingService() {
        for (Booking* booking : bookings) delete booking;
    }

    Booking* findBooking(int id) const {
        for (Booking* booking : bookings)
            if (booking->getBookingId() == id) return booking;
        return nullptr;
    }

    Booking* bookTicket(Customer customer, Show* show,
                        const vector<int>& seatNumbers,
                        Payment* payment) {
        if (!show || seatNumbers.empty()) {
            cout << "Invalid show or no seats selected.\n";
            delete payment;
            return nullptr;
        }

        set<int> uniqueSeats;
        vector<ShowSeat*> selected;

        for (int number : seatNumbers) {
            if (!uniqueSeats.insert(number).second) {
                cout << "Seat " << number << " selected more than once.\n";
                delete payment;
                return nullptr;
            }

            ShowSeat* ss = show->findShowSeat(number);
            if (!ss) {
                cout << "Seat " << number << " does not exist.\n";
                delete payment;
                return nullptr;
            }

            if (!ss->isAvailable()) {
                cout << "Seat " << number << " is already booked.\n";
                delete payment;
                return nullptr;
            }

            selected.push_back(ss);
        }

        double total = PriceCalculator::calculate(selected);

        cout << "\nTotal amount: Rs. " << total << '\n';

        if (!payment->pay(total)) {
            cout << "Payment failed. Booking cancelled and seats released.\n";
            delete payment;
            return nullptr;
        }

        for (ShowSeat* ss : selected) ss->book();

        Booking* booking =
            new Booking(customer, show, selected, total, payment);

        bookings.push_back(booking);

        cout << "\nBooking successful!\n";
        TicketPrinter::print(*booking);
        return booking;
    }

    bool cancelBooking(int id) {
        Booking* booking = findBooking(id);

        if (!booking) {
            cout << "Booking not found.\n";
            return false;
        }

        if (booking->getStatus() == BookingStatus::CANCELLED) {
            cout << "Booking is already cancelled.\n";
            return false;
        }

        booking->cancel();
        cout << "Booking " << id << " cancelled successfully.\n";
        return true;
    }

    void listBookings() const {
        if (bookings.empty()) {
            cout << "No bookings available.\n";
            return;
        }

        cout << "\n--------- ALL BOOKINGS ---------\n";
        for (Booking* booking : bookings) {
            cout << "ID: " << booking->getBookingId()
                 << " | Customer: " << booking->getCustomer().getName()
                 << " | Movie: " << booking->getShow()->getMovie()->getTitle()
                 << " | Amount: Rs. " << booking->getTotalAmount()
                 << " | Status: "
                 << (booking->getStatus() == BookingStatus::CONFIRMED
                     ? "CONFIRMED" : "CANCELLED")
                 << '\n';
        }
    }
};
