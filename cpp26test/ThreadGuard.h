//
// Created by wsnzg6 on 2026/7/9.
// Copyright(c) 2026 ZGTeam233.
//

#ifndef THREADGUARD_H
#define THREADGUARD_H

#include <thread>


// 由于 join() 和 detach() 都必须被调用，否则析构会 terminate
// 最佳实践是编写一个 RAII 包装器，在析构时自动 join
class ThreadGuard {
    std::thread t;
public:
    explicit ThreadGuard(std::thread t_) : t(std::move(t_)) {}
    ~ThreadGuard() {
        if (t.joinable())
            t.join();
    }

    ThreadGuard(const ThreadGuard&) = delete;
    ThreadGuard &operator=(const ThreadGuard&) = delete;
};

#endif // THREADGUARD_H