//
// Created by wsnzg6 on 2026/7/12.
// Copyright(c) 2026 ZGTeam233.
//

#ifndef MOVETEST_RESOURCEPOOL_H
#define MOVETEST_RESOURCEPOOL_H

#include <vector>
#include <memory>
#include <utility>
#include <stdexcept>

namespace resource_pool {
    template <typename T>
    class ResourcePool {
        std::vector<T*> pool;
        bool moved_from = false;  // 防止移动后的悬空访问

    public:
        ResourcePool() = default;

        // ========== 禁用拷贝（防止重复释放） ==========
        ResourcePool(const ResourcePool&) = delete;
        ResourcePool& operator=(const ResourcePool&) = delete;

        // ========== 移动构造 ==========
        ResourcePool(ResourcePool&& other) noexcept
            : pool(std::move(other.pool)), moved_from(false) {
            other.moved_from = true;
            other.pool.clear();  // 确保源对象状态干净
        }

        // ========== 移动赋值 ==========
        ResourcePool& operator=(ResourcePool&& other) noexcept {
            if (this != &other) {
                // 先清理当前资源
                for (auto* ptr : pool) {
                    delete ptr;
                }
                // 转移所有权
                pool = std::move(other.pool);
                moved_from = false;

                other.moved_from = true;
                other.pool.clear();
            }
            return *this;
        }

        // ========== 添加资源 ==========
        void add(T* obj) {
            if (moved_from) {
                throw std::runtime_error("Cannot add to a moved-from ResourcePool");
            }
            pool.push_back(obj);
        }

        // ========== 左值版本：返回指针拷贝 ==========
        std::vector<T*> getAll() const {
            if (moved_from) {
                throw std::runtime_error("Cannot access a moved-from ResourcePool");
            }
            return pool;  // 返回 vector 的拷贝
        }

        // ========== 右值版本：转移所有权 ==========
        std::vector<std::unique_ptr<T>> takeAll() {
            if (moved_from) {
                return {};  // 已移动过，返回空
            }

            std::vector<std::unique_ptr<T>> result;
            result.reserve(pool.size());

            // 将裸指针所有权转移到 unique_ptr
            for (auto* ptr : pool) {
                result.emplace_back(ptr);
            }

            // 关键：清空原容器，防止析构时重复释放
            pool.clear();
            moved_from = true;

            return result;  // 依赖 NRVO 或隐式移动语义
        }

        // ========== 析构函数 ==========
        ~ResourcePool() {
            if (!moved_from) {
                for (auto* ptr : pool) {
                    delete ptr;
                }
            }
            pool.clear();
        }
    };
} // resource_pool

#endif //MOVETEST_RESOURCEPOOL_H
