#pragma once
#include <vector>
using namespace std;

class PriceCalculator {
public:
    static double calculate(const vector<ShowSeat*>& seats) {
        double total = 0;
        for (ShowSeat* ss : seats)
            total += Seat::price(ss->getSeat()->getType());
        return total;
    }
};
