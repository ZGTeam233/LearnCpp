//
// Created by wsnzg6 on 2026/7/11.
// Copyright(c) 2026 ZGTeam233.
//

#include "TodoList.h"
#include "../core.h"

using namespace done;

void done_main() {
    TodoList myList;
    int choice;
    std::string inputDesc;
    int taskIndex;

    while (true) {
        std::cout << "\n=== 简易待办事项管理器 ===" << std::endl;
        std::cout << "1. 添加任务\n2. 查看所有任务\n3. 完成任务\n4. 删除任务\n5. 退出\n";
        std::cout << "请选择操作: ";

        if (!(std::cin >> choice)) {
            std::cout << "请输入数字！\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
        case 1:
            std::cout << "请输入任务内容: ";
            std::cin.ignore(); // 清除之前的换行符
            std::getline(std::cin, inputDesc);
            myList.addTask(inputDesc);
            break;
        case 2:
            myList.showTasks();
            break;
        case 3:
            std::cout << "请输入要完成的任务编号: ";
            std::cin >> taskIndex;
            myList.completeTask(taskIndex);
            break;
        case 4:
            std::cout << "请输入要删除的任务编号: ";
            std::cin >> taskIndex;
            myList.deleteTask(taskIndex);
            break;
        case 5:
            std::cout << "感谢使用，再见！" << std::endl;
            return 0;
        default:
            std::cout << "无效的选择，请重试。\n";
        }
    }
}