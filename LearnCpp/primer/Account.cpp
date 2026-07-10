//
// Created by wsnzg6 on 2026/7/10.
//

#include "Account.h"

namespace primer {
    double Account::initRate() {
        // TODO: 完善初始化利率
        return 0;
    }

    void Account::rate(double newRate) {
        interestRate = newRate;
    }

    double Account::interestRate = initRate();
} // primer