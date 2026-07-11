//
// Created by wsnzg6 on 2026/7/11.
// Copyright(c) 2026 ZGTeam233.
//

#ifndef LEARNCPP_TODOLIST_H
#define LEARNCPP_TODOLIST_H

#include "Task.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>


namespace std_done {
    // 待办事项管理类
    class TodoList {
        std::vector<Task> tasks;
        const std::string filename = "tasks.txt";
        void loadFromFile(); // 从文件加载
        void saveToFile() const; // 保存到文件
    public:
        TodoList() { loadFromFile(); }
        ~TodoList() { saveToFile(); } // 析构时自动保存
        void addTask(const std::string& desc);
        void showTasks() const;
        void completeTask(int index);
        void deleteTask(int index);
    };
} // std_done

#endif //LEARNCPP_TODOLIST_H
