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

    cout << "\n也是给这个C++学习项目" << endl;
    cout << "\t加了一个主程序啊" << endl;
    cout << "\n请选择打开的项目" << endl;
    cout << "\t1. 类与对象练习：Person" << endl;
    cout << "\t2. C++猜数字" << endl;
    cout << "\t3. C++ Primer：Sales_data" << endl;
    cout << "\t4. 成绩管理系统" << endl;
    cout << "\t5. 学生管理系统" << endl;
    cout << "\t0. 退出" << endl;
    cout << "请选择：";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: class_main(); break;
        case 2: guess(); break;
        case 3: sales_main(); break;
        case 4: grade_main(); break;
        case 5: stu_sys(); break;
        default: break;
    }
    return 0;
}
