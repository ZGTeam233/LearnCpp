#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

int main() {
    Person p(17, "Jim");
    print(cout, p) << endl;
    p.set(18, "Tom").eat();
    return 0;
}