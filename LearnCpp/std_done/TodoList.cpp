//
// Created by wsnzg6 on 2026/7/11.
// Copyright(c) 2026 ZGTeam233.
//

#include "TodoList.h"

namespace done {
    // 从文件加载
    void TodoList::loadFromFile() {
        std::ifstream file(filename);
        if (!file.is_open()) return;

        std::string desc;
        bool status;
        while (file >> status) {
            file.ignore(); // 跳过空格
            std::getline(file, desc);
            tasks.emplace_back(desc, status);
        }
        file.close();
    }

    // 保存到文件
    void TodoList::saveToFile() const {
        std::ofstream file(filename);
        for (const auto& task : tasks) {
            file << task.isCompleted << " " << task.description << "\n";
        }
    }

    void TodoList::addTask(const std::string& desc) {
        if (desc.empty()) return;
        tasks.emplace_back(desc);
        saveToFile(); // 每次操作后保存
        std::cout << "任务添加成功！\n";
    }

    void TodoList::showTasks() const {
        if (tasks.empty()) {
            std::cout << "\n列表空空如也，快去添加任务吧！\n";
            return;
        }

        std::cout << "\n" << std::setfill('=') << std::setw(30) << "" << std::endl;
        std::cout << "     std::done 任务清单" << std::endl;
        std::cout << std::setfill('-') << std::setw(30) << "" << std::setfill(' ') << std::endl;

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << std::left << std::setw(4) << i + 1
                << (tasks[i].isCompleted ? "[✔]" : "[ ]") << " "
                << tasks[i].description << std::endl;
        }
        std::cout << std::setfill('=') << std::setw(30) << "" << std::setfill(' ') << std::endl;
    }

    void TodoList::completeTask(int index) {
        if (index > 0 && index <= static_cast<int>(tasks.size())) {
            tasks[index - 1].isCompleted = true;
            saveToFile();
            std::cout << "⭐ 任务 " << index << " 已完成，干得漂亮！\n";
        }
        else {
            std::cout << "❌ 无效编号！\n";
        }
    }

    void TodoList::deleteTask(int index) {
        if (index > 0 && index <= static_cast<int>(tasks.size())) {
            tasks.erase(tasks.begin() + (index - 1));
            saveToFile();
            std::cout << "🗑️ 任务已从列表中移除。\n";
        }
        else {
            std::cout << "❌ 无效编号！\n";
        }
    }
} // done
