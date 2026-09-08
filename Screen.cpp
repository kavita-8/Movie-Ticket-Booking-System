#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Screen {
private:
    int screenNumber;
    vector<Seat*> seats;

public:
    Screen(int number) : screenNumber(number) {}

    ~Screen() {
        for (Seat* seat : seats) delete seat;
    }

    int getScreenNumber() const { return screenNumber; }

    void addSeat(int number, SeatType type) {
        seats.push_back(new Seat(number, type));
    }

    const vector<Seat*>& getSeats() const { return seats; }
    Seat* findSeat(int number) const {
        for (Seat* seat : seats)
            if (seat->getSeatNumber() == number) return seat;
        return nullptr;
    }
};
