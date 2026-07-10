#include <iostream>
#include "test.h"

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif // _WIN32

    int choice = 0;
    cout << ": ";
    cin >> choice;
    switch (choice) {
        case 1: test1(); break;
        case 2: test2(); break;
        default: break;
    }
    return 0;
}
