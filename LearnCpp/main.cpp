//
// Created by wsnzg6 on 2026/6/19.
// Copyright(c) 2026 ZGTeam233.
//

#include <iostream>
#include "core.h"

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

using namespace std;


void use_primer() {
    cout << "\n请选择打开的项目" << endl
        << "\t1. C++ Primer：Sales_data" << endl
        << "\t2. C++ Primer：Screen" << endl
        << "\t3. C++ Primer：Account" << endl
        << "\t4. C++ Primer：排序算法" << endl
        << "\t5. C++ Primer：算法和 Lambda" << endl
        << "\t0. 退出" << endl;
    cout << "请选择: ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: use_sales();
        break;
    case 2: use_screen();
        break;
    case 3: use_account();
        break;
    case 4: use_sort();
        break;
    case 5: use_biggies();
        break;
    default: break;
    }
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8); // 可选：同时设置输入代码页
#endif // _WIN32

    cout << "\n也是给这个C++学习项目" << endl
        << "\t加了一个主程序啊" << endl
        << "\n请选择打开的项目" << endl
        << "\t1. 类与对象练习：Person" << endl
        << "\t2. C++猜数字" << endl
        << "\t3. C++ Primer 系列" << endl
        << "\t4. 成绩管理系统" << endl
        << "\t5. 学生管理系统" << endl
        << "\t6. std::done 一个 Todo 应用" << endl
        << "\t0. 退出" << endl;
    cout << "请选择: ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1: use_person();
        break;
    case 2: guess();
        break;
    case 3: use_primer();
        break;
    case 4: use_grade();
        break;
    case 5: use_student();
        break;
    case 6: done_main();
        break;
    default: break;
    }
    return 0;
}
