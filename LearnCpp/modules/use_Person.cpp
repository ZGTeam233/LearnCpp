#include <iostream>
#include "Person.h"
#include "../core.h"

using namespace std;
using namespace ps;

void use_person() {
    Person p(17, "Jim");
    cout << p << endl;
    p.set(18, "Tom").eat();
}