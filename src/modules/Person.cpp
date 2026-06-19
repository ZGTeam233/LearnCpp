#include <iostream>
#include "Person.h"

namespace ps {
    std::istream &operator>>(std::istream &is, Person &p) {
        is >> p.age >> p.name;
        if (!is)
            p = Person();
        return is;
    }

    std::ostream &operator<<(std::ostream &os, const Person &p) {
        os << p.name << " (" << p.age << ")";
        return os;
    }

    Person::Person(std::istream &is) {
        is >> *this;
    }
} // ps