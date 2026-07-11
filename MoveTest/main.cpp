//
// Created by wsnzg6 on 2026/7/11.
// Copyright(c) 2026 ZGTeam233.
//

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
        case 1: use_my_buffer(); break;
        case 2: use_simple_string(); break;
        default: break;
    }
    return 0;
}
