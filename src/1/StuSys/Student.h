#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

// 学生类
class Student {
private:
    std::string name;   // 姓名
    std::string id;     // 学号
    double score;  // 成绩

public:
    // 构造函数
    Student(std::string n, std::string i, double s) : name(n), id(i), score(s) {}

    // 显示学生信息
    void display() const {
        std::cout << "学号: " << id << "\t姓名: " << name << "\t成绩: " << score << std::endl;
    }

    // 获取成绩（用于计算平均分）
    double getScore() const { return score; }
};

#endif // STUDENT_H