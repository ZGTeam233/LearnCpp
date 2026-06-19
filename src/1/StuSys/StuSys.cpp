#include <iostream>
#include <vector>
#include <string>
#include "Student.h"

using namespace std;

int main() {
    vector<Student> students;  // 存储学生信息的动态数组
    int choice;

    do {
        // 菜单界面
        cout << "\n=== 学生成绩管理系统 ===" << endl;
        cout << "1. 添加学生信息" << endl;
        cout << "2. 显示所有学生" << endl;
        cout << "3. 计算平均成绩" << endl;
        cout << "0. 退出程序" << endl;
        cout << "请输入操作选项: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, id;
            double score;
            cout << "请输入学号: ";
            cin >> id;
            cout << "请输入姓名: ";
            cin >> name;
            cout << "请输入成绩: ";
            cin >> score;
            students.emplace_back(name, id, score);  // 直接构造学生对象
            cout << "✅ 添加成功！" << endl;
            break;
        }
        case 2: {
            if (students.empty()) {
                cout << "⚠️ 暂无学生信息！" << endl;
            }
            else {
                cout << "\n学生列表:" << endl;
                for (const auto& s : students) {
                    s.display();
                }
            }
            break;
        }
        case 3: {
            if (students.empty()) {
                cout << "⚠️ 暂无学生信息，无法计算平均分！" << endl;
            }
            else {
                double total = 0;
                for (const auto& s : students) {
                    total += s.getScore();
                }
                cout << "📊 班级平均成绩: " << total / students.size() << endl;
            }
            break;
        }
        case 0:
            cout << "👋 感谢使用，再见！" << endl;
            break;
        default:
            cout << "❌ 无效选项，请重新输入！" << endl;
        }
    } while (choice != 0);

    return 0;
}