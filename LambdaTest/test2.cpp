//
// Created by wsnzg6 on 2026/7/10.
// Copyright(c) 2026 ZGTeam233.
//

#include <iostream>
#include <unordered_map>
#include "test.h"

using namespace std;

auto make_memoized_factorial() {
    // 提示：你需要返回一个 lambda。
    // 提示：你需要使用 C++14 的初始化捕获来创建一个空的 map。
    // 提示：别忘了 mutable！
    return [cache = unordered_map<int, long long>()](int n) mutable {
        auto it = cache.find(n);
        if (it == cache.cend()) {
            long long result = 1;
            for (int i = n; i > 0; i--) {
                result *= i;
            }
            cache[n] = result;
            return result;
        }
        return cache[n];
    };
}

void test2() {
    // 生成带有记忆功能的计算器
    auto factorial = make_memoized_factorial();

    cout << "计算 5! ..." << endl;
    cout << "结果: " << factorial(5) << "\n\n"; // 应该计算并缓存

    cout << "计算 3! ..." << endl;
    cout << "结果: " << factorial(3) << "\n\n"; // 应该计算并缓存

    cout << "计算 6! ..." << endl;
    cout << "结果: " << factorial(6) << "\n\n"; // 应该计算并缓存

    cout << "再次计算 5! (应该命中缓存) ..." << endl;
    cout << "结果: " << factorial(5) << "\n\n"; // 应该直接从缓存读取，不重新计算
}