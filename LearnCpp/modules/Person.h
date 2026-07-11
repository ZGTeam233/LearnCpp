//
// Copyright(c) 2026 ZGTeam233.
//

#ifndef LEARNCPP_PERSON_H
#define LEARNCPP_PERSON_H

#include <iostream>
#include <string>

namespace ps {
    class Person {
        friend std::istream& operator>>(std::istream&, Person&);
        friend std::ostream& operator<<(std::ostream&, const Person&);

    public:
        Person() = default;

        Person(int a, const std::string& n) : age(a), name(n) {
        }

        Person(std::istream&);

        void eat() const {
            std::cout << name << " is eating." << std::endl;
            std::cout << "He is " << age << " years old." << std::endl;
        }

        Person& get(int& a, std::string& n) {
            doGet(a, n);
            return *this;
        }

        const Person& get(int& a, std::string& n) const {
            doGet(a, n);
            return *this;
        }

        Person& set(int a, const std::string& n) {
            age = a;
            name = n;
            return *this;
        }

    private:
        int age = 0;
        std::string name;

        void doGet(int& a, std::string& n) const {
            a = age;
            n = name;
        }
    };

    std::istream& operator>>(std::istream&, Person&);
    std::ostream& operator<<(std::ostream&, const Person&);
} // ps
#endif //LEARNCPP_PERSON_H