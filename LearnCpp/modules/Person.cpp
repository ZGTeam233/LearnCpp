//
// Copyright(c) 2026 ZGTeam233.
//

#include <iostream>
#include "Person.h"

using namespace std;

namespace ps {
    istream &operator>>(istream &is, Person &p) {
        is >> p.age >> p.name;
        if (!is)
            p = Person();
        return is;
    }

    ostream &operator<<(ostream &os, const Person &p) {
        os << p.name << " (" << p.age << ")";
        return os;
    }

    Person::Person(istream &is) {
        is >> *this;
    }
} // ps