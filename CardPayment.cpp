#pragma once
#include <iostream>
using namespace std;

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Card payment amount: Rs. " << amount << '\n';
        cout << "Enter 1 if payment is successful, 0 if failed: ";
        int ok;
        cin >> ok;
        return ok == 1;
    }

    string methodName() const override { return "Card"; }
};
