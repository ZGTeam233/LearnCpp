#include <iostream>
#include "core.h"

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

using namespace std;

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
        << "\t3. C++ Primer：Sales_data" << endl
        << "\t4. 成绩管理系统" << endl
        << "\t5. 学生管理系统" << endl
        << "\t6. C++ Primer：Screen" << endl
        << "\t0. 退出" << endl;
    cout << "请选择：";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: person_main(); break;
        case 2: guess(); break;
        case 3: sales_main(); break;
        case 4: grade_main(); break;
        case 5: student_main(); break;
        case 6: screen_main(); break;
        default: break;
    }
    return 0;
}
