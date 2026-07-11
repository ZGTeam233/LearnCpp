//
// Created by wsnzg6 on 2026/7/11.
// Copyright(c) 2026 ZGTeam233.
//

#ifndef MYBUFFER_H
#define MYBUFFER_H

#include <iostream>

struct MyBuffer {
    int* data;
    int size;

    // 1. 普通构造函数
    MyBuffer(int s) : size(s), data(new int[s]) {
        std::cout << "[1] 普通构造\n";
    }

    // 2. 拷贝构造函数 (参数是 const 左值引用)
    MyBuffer(const MyBuffer& other) : size(other.size), data(new int[other.size]) {
        std::cout << "[2] 拷贝构造\n";
    }

    // 3. 移动构造函数 (参数是 右值引用 &&)
    MyBuffer(MyBuffer&& other) noexcept : size(other.size), data(other.data) {
        // 窃取资源后，把原对象“掏空”
        other.data = nullptr;
        other.size = 0;
        std::cout << "[3] 移动构造\n";
    }

    ~MyBuffer() {
        delete[] data;
    }
};

#endif // MYBUFFER_H
