#include <iostream>
#include "Screen.h"
#include "../core.h"

using namespace std;
using namespace primer;

void use_screen() {
    Screen myScreen(5, 3);
    const Screen blank(5, 3);
    myScreen.set('#').display(cout);
    blank.display(cout);
}