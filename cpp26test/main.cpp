#include <iostream>
#include <thread>

using namespace std;

void hello() {
    cout << "Hello from thread " << this_thread::get_id() << endl;
}

int main() {
    thread t(hello);
    t.join();
    return 0;
}