#include <iostream>
#include <thread>
#include "ThreadGuard.h"

using namespace std;

void hello() {
    cout << "Hello from thread " << this_thread::get_id() << endl;
}

void _print(int a, const string &s) {
    cout << a << ": " << s << endl;
}

void test1() {
    std::thread t(hello); // 线程 t 开始执行 hello()
    t.join(); // 等待线程结束
}

void test2() {
    string str = "hello";
    thread t1(_print, 42, str);
    thread t2(_print, 42, cref(str));
    t1.join();
    t2.join();
}

void test3() {
    ThreadGuard guard(thread(hello)); // 即使抛异常，析构也会 join
}

int main() {
    int choice = 0;
    cout << ": ";
    cin >> choice;
    switch (choice) {
        case 1: test1(); break;
        case 2: test2(); break;
        case 3: test3(); break;
        default: break;
    }
    return 0;
}