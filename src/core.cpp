// Created by wsnzg6 on 2026/6/19.

#include <iostream>
#include <string>
#include <vector>
#include "modules/Person.hpp"
#include "modules/Sales_data.hpp"
#include "modules/DebugUtil.hpp"
#include "modules/grade.hpp"
#include "modules/Student.hpp"

void class_main() {
    ps::Person p(17, "Jim");
    std::cout << p << std::endl;
    p.set(18, "Tom").eat();
}

// GOD, HOPE IT THIS CODE WORKS FINE NOW.
void guess() {
    int guess = 0;
    int attempts = 0; // 猜测次数
    std::vector<int> password = { 42, 15, 7, 93, 28 }; // 猜数字游戏答案
    int round = 0; // 当前轮数
    int choice;
    std::cout << "Welcome to the Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100." << std::endl;
    std::cout << "Can you guess what it is ?" << std::endl;
    std::cout << "You have seven attempts to guess the correct number." << std::endl;
    while (guess != password[round]) {
        if (attempts < 7) {
            // 允许猜测
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            attempts++;

            if (guess < password[round]) {
                std::cout << "Too low! Try again." << std::endl; // 猜测过低
            } else if (guess > password[round]) {
                std::cout << "Too high! Try again." << std::endl; // 猜测过高
            } else {
                // 猜测正确
                std::cout << "Congratulations! You've guessed the correct number: "
                        << password[round] << "." << std::endl;
                if (round == 4) {
                    // 完成所有轮次
                    std::cout << "You've completed all rounds! Well done!" << std::endl;
                    break;
                }
                else {
                    // 询问是否继续下一轮
                    std::cout << "Wanna try the next number? Input 1 to continue or 0 to quit: " << std::endl;
                    std::cin >> choice;
                    if (choice == 1) {
                        // 继续下一轮
                        round++;
                        attempts = 0;
                        guess = 0;
                    }
                    else {
                        // 退出游戏
                        std::cout << "Thanks for playing! Goodbye!" << std::endl;
                        break;
                    }
                }
            }
        }
        else {
            // 超过七次未猜中
            std::cout << "Sorry, you've used all your attempts. The correct number was "
                    << password[round] << "." << std::endl;
            break;
        }
    }
}

int sales_main() {
    Sales_data total; // 保存和的变量
    std::cout << "<ISBN> <units_sold> <price>" << std::endl; // 提示输入格式
    // 读入第一笔交易，并确保有数据可以处理
    if (std::cin >> total) {
        Sales_data trans;

        // 读入剩余的交易
        while (std::cin >> trans) {
            // 如果我们仍在处理相同的书
            if (total.isbn() == trans.isbn())
                total.combine(trans); // 更新总销售额
            else {
                // 输出前一本书的结果
                std::cout << total << std::endl; // 打印结果并换行
                total = trans; // total现在表示下一本书的销售额
            }
        }
        std::cout << total << std::endl; // 输出最后一本书的结果
    } else {
        // 没有输入，给出提示
        DebugLog::error(MAKE_DEBUG_ERR(__FUNCTION__, "No data?"));
        return -1;
    }
    return 0;
}

int grade_main() {
    int choice;

    while (true) {
        std::cout << "\nPlease select an action to perform(enter a number 1 - 4):\n";
        std::cout << "1. Check grade level\n";
        std::cout << "2. Determine if scholarship is awarded\n"; // 判断是否获得奖学金
        std::cout << "3. Show this semester's evaluation\n"; // 显示本学期评价
        std::cout << "4. Exit program\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                while (checkLevel() == -1) {
                    // 重新调用函数让用户输入正确的成绩
                    std::cerr << "Invalid grade. Please enter a number between 0 and 100.\n";
                }
                break;
            case 2:
                while (true) {
                    int result = checkScholarship();
                    if (result == 0) {
                        break; // 正常退出，跳出循环
                    } else if (result == -1) {
                        std::cerr << "Invalid grade. Please enter a number between 0 and 100.\n";
                    } else if (result == -2) {
                        std::cerr << "Invalid input for choice. Please enter Y or N.\n";
                    }
                }
                break;
            case 3:
                while (showEvaluation() == -1) {
                    // 重新调用函数让用户输入正确的成绩
                    std::cerr << "Invalid average grade. Please enter a number between 0 and 100.\n";
                }
                break;
            case 4:
                std::cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                std::cerr << "Invalid choice. Please enter a number between 1 and 4.\n";
                break;
        }
    }
}

void stu_sys() {
    std::vector<Student> students;  // 存储学生信息的动态数组
    int choice;

    do {
        // 菜单界面
        std::cout << "\n=== 学生成绩管理系统 ===" << std::endl;
        std::cout << "1. 添加学生信息" << std::endl;
        std::cout << "2. 显示所有学生" << std::endl;
        std::cout << "3. 计算平均成绩" << std::endl;
        std::cout << "0. 退出程序" << std::endl;
        std::cout << "请输入操作选项: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, id;
                double score;
                std::cout << "请输入学号: ";
                std::cin >> id;
                std::cout << "请输入姓名: ";
                std::cin >> name;
                std::cout << "请输入成绩: ";
                std::cin >> score;
                students.emplace_back(name, id, score);  // 直接构造学生对象
                std::cout << "✅ 添加成功！" << std::endl;
                break;
            }
            case 2: {
                if (students.empty()) {
                    std::cout << "⚠️ 暂无学生信息！" << std::endl;
                }
                else {
                    std::cout << "\n学生列表:" << std::endl;
                    for (const auto& s : students) {
                        s.display();
                    }
                }
                break;
            }
            case 3: {
                if (students.empty()) {
                    std::cout << "⚠️ 暂无学生信息，无法计算平均分！" << std::endl;
                }
                else {
                    double total = 0;
                    for (const auto& s : students) {
                        total += s.getScore();
                    }
                    std::cout << "📊 班级平均成绩: " << total / students.size() << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "👋 感谢使用，再见！" << std::endl;
                break;
            default:
                std::cout << "❌ 无效选项，请重新输入！" << std::endl;
        }
    } while (choice != 0);
}