//
// Created by wsnzg6 on 2026/7/11.
// Copyright(c) 2026 ZGTeam233.
//

#ifndef LEARNCPP_TASK_H
#define LEARNCPP_TASK_H

#include <string>

namespace done {
    // 定义“任务”结构体
    struct Task {
        std::string description;
        bool isCompleted;

        Task(std::string desc, bool completed = false)
            : description(desc), isCompleted(completed) {
        }
    };
} // done

#endif //LEARNCPP_TASK_H
