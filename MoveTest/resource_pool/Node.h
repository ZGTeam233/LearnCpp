//
// Created by wsnzg6 on 2026/7/12.
// Copyright(c) 2026 ZGTeam233.
//

#ifndef MOVETEST_NODE_H
#define MOVETEST_NODE_H

#include <iostream>

namespace resource_pool {
    // 示例资源类型
    struct Node {
        int id = 0;
        Node(int i) : id(i) { std::cout << "Node " << id << " created\n"; }
        ~Node() { std::cout << "Node " << id << " destroyed\n"; }
    };
} // resource_pool

#endif //MOVETEST_NODE_H
