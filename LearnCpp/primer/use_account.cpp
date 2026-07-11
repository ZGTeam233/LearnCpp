//
// Created by wsnzg6 on 2026/7/10.
//

#include "Account.h"
#include "../core.h"

using namespace primer;

void use_account() {
    double r = Account::rate();
    Account ac1;
    Account* ac2 = &ac1;
    r = ac1.rate();
    r = ac2->rate();
}