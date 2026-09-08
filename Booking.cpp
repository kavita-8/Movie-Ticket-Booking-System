#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class BookingStatus { CONFIRMED, CANCELLED };

class Booking {
private:
    static int nextBookingId;
    int bookingId;
    Customer customer;
    Show* show;
    vector<ShowSeat*> seats;
    double totalAmount;
    BookingStatus status;
    Payment* payment;

public:
    Booking(Customer customer, Show* show,
            const vector<ShowSeat*>& seats,
            double total, Payment* payment)
        : bookingId(nextBookingId++), customer(customer), show(show),
          seats(seats), totalAmount(total),
          status(BookingStatus::CONFIRMED), payment(payment) {}

    ~Booking() {
        delete payment;
    }

    int getBookingId() const { return bookingId; }
    const Customer& getCustomer() const { return customer; }
    Show* getShow() const { return show; }
    const vector<ShowSeat*>& getSeats() const { return seats; }
    double getTotalAmount() const { return totalAmount; }
    BookingStatus getStatus() const { return status; }
    Payment* getPayment() const { return payment; }

    void cancel() {
        if (status == BookingStatus::CANCELLED) return;
        for (ShowSeat* ss : seats) ss->release();
        status = BookingStatus::CANCELLED;
    }
};

int Booking::nextBookingId = 1001;
