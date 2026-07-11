//
// Created by wsnzg6 on 2026/7/10.
//

#ifndef LEARNCPP_ACCOUNT_H
#define LEARNCPP_ACCOUNT_H

#include <string>

namespace primer {
    class Account {
    public:
        void calculate() { amount += amount * interestRate; }
        static double rate() { return interestRate; }
        static void rate(double);

    private:
        std::string owner;
        double amount = 0;
        static double interestRate;
        static double initRate();
        static constexpr int period = 30;
        double daily_tbl[period];
    };
} // primer

#endif //LEARNCPP_ACCOUNT_H
