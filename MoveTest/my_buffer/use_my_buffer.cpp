//
// Created by wsnzg6 on 2026/7/11.
// Copyright(c) 2026 ZGTeam233.
//

#include "../test.h"
#include <utility> // std::move 所在的头文件
#include "MyBuffer.h"

using namespace my_buffer;

void use_my_buffer () {
    MyBuffer buf1(10); // 语句 A
    MyBuffer buf2 = buf1; // 语句 B
    MyBuffer buf3 = std::move(buf1); // 语句 C
}
