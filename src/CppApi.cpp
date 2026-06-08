#include <iostream>

// 这个程序是用来测试 Visual Studio 的 C++ 编译器版本和 C++ 标准支持的
int main() {
    std::cout << "C++ version: " << __cplusplus << std::endl;
    std::cout << "Compiler version: " << _MSC_FULL_VER << std::endl;
    return 0;
}