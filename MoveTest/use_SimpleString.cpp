//
// Created by wsnzg6 on 2026/7/11.
// Copyright(c) 2026 ZGTeam233.
//

#include <iostream>
#include "SimpleString.h"
#include "test.h"

void use_simple_string() {
    std::cout << "--- 测试开始 ---\n";
    SimpleString s1("Hello");
    SimpleString s2("World");

    std::cout << "\n--- 执行移动赋值: s1 = std::move(s2) ---\n";
    s1 = std::move(s2); // 这里会调用你写的移动赋值运算符

    std::cout << "\n--- 查看结果 ---\n";
    s1.print(); // 预期输出: World
    s2.print(); // 预期输出: nullptr (被掏空了)

    std::cout << "\n--- 程序结束，触发析构 ---\n";
}