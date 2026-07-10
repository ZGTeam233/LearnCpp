//
// Created by wsnzg6 on 2026/7/10.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

namespace primer {
    class Account {
    public:
        void calculate() { amount += amount * interestRate; }
        static double rate() { return interestRate; }
        static void rate(double);
    private:
        std::string owner;
        double amount;
        static double interestRate;
        static double initRate();
    };
} // primer

#endif // ACCOUNT_H
