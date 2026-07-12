//
// Created by wsnzg6 on 2026/7/12.
// Copyright(c) 2026 ZGTeam233.
//

#include <iostream>
#include "Node.h"
#include "ResourcePool.h"
#include "../test.h"

using namespace resource_pool;

void test_takeAll_safety() {
    std::cout << "\n=== Test: takeAll() 后析构安全性 ===\n";

    {
        ResourcePool<Node> pool;
        pool.add(new Node(1));
        pool.add(new Node(2));
        pool.add(new Node(3));

        // 夺走所有资源
        auto resources = pool.takeAll();

        std::cout << "Pool 即将析构（应该没有 Node 被销毁）...\n";
    }  // pool 析构，但 pool 已空，不会 delete

    std::cout << "resources 即将析构（应该看到 Node 1,2,3 被销毁）...\n";
    // resources 析构时，unique_ptr 自动释放内存
}

void test_move_semantics() {
    std::cout << "\n=== Test: 移动语义 ===\n";

    ResourcePool<Node> pool1;
    pool1.add(new Node(10));
    pool1.add(new Node(20));

    // 移动构造
    ResourcePool<Node> pool2(std::move(pool1));

    std::cout << "pool1 已移动，尝试访问会抛异常...\n";
    try {
        pool1.getAll();
    } catch (const std::exception& e) {
        std::cout << "捕获异常: " << e.what() << "\n";
    }

    std::cout << "pool2 析构...\n";
}

void test_normal_destruction() {
    std::cout << "\n=== Test: 正常析构 ===\n";

    ResourcePool<Node> pool;
    pool.add(new Node(100));
    pool.add(new Node(200));

    std::cout << "pool 即将析构（应该看到 Node 100,200 被销毁）...\n";
}

void test_res_pool() {
    test_takeAll_safety();
    test_move_semantics();
    test_normal_destruction();
}