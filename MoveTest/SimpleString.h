//
// Created by wsnzg6 on 2026/7/11.
// Copyright(c) 2026 ZGTeam233.
//

#ifndef MOVETEST_SIMPLESTRING_H
#define MOVETEST_SIMPLESTRING_H

#include <iostream>
#include <cstring>
#include <utility>

class SimpleString {
    char *data;
public:
    // 普通构造
    SimpleString(const char *str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
        std::cout << "[普通构造] 创建: " << data << "\n";
    }

    // 析构函数
    ~SimpleString() {
        if (data)
            std::cout << "[析构] 销毁: " << data << "\n";
        else
            std::cout << "[析构] 销毁空壳\n";
        delete[] data;
    }

    // 拷贝构造 (已实现)
    SimpleString(const SimpleString &other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        std::cout << "[拷贝构造] 复制: " << data << "\n";
    }

    SimpleString& operator=(SimpleString &&other) {
        // 1. 检查自赋值
        if (this != &other) {
            // 2. 释放旧内存
            delete[] data;
            // 3. 窃取指针
            data = other.data;
            // 4. 掏空 other
            other.data = nullptr;
        }
        // 5. 返回 *this
        return *this;
    }

    void print() const {
        std::cout << "内容: " << (data ? data : "nullptr") << "\n";
    }
};

#endif // MOVETEST_SIMPLESTRING_H
