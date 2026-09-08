#pragma once
#include <iostream>
using namespace std;

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Cash payment amount: Rs. " << amount << '\n';
        cout << "Enter 1 if cash received, 0 if failed: ";
        int ok;
        cin >> ok;
        return ok == 1;
    }

    string methodName() const override { return "Cash"; }
};
