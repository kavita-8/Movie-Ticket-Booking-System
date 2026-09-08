#pragma once
#include <string>
using namespace std;

enum class SeatType { SILVER, GOLD, PLATINUM };

class Seat {
private:
    int seatNumber;
    SeatType type;

public:
    Seat(int number, SeatType type) : seatNumber(number), type(type) {}

    int getSeatNumber() const { return seatNumber; }
    SeatType getType() const { return type; }

    static string typeName(SeatType type) {
        switch (type) {
            case SeatType::SILVER: return "Silver";
            case SeatType::GOLD: return "Gold";
            case SeatType::PLATINUM: return "Platinum";
        }
        return "Unknown";
    }

    static double price(SeatType type) {
        switch (type) {
            case SeatType::SILVER: return 150.0;
            case SeatType::GOLD: return 250.0;
            case SeatType::PLATINUM: return 400.0;
        }
        return 0.0;
    }
};
