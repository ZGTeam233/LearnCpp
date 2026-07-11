//
// Copyright(c) 2026 ZGTeam233.
//

#include <iostream>
#include <cctype>
#include <string>
#include "../core.h"

using namespace std;

int checkLevel() {
    int grade;
    cout << "\n=== CHECK LEVEL ===\n";
    cout << "Enter your grade (0-100): ";
    cin >> grade;
    if (grade > 100 || grade < 0) {
        return -1; // 带错误退出函数
    }
    switch (grade / 10) {
    case 10:
    case 9:
        cout << "Grade level: A, outstanding\n";
        break;
    case 8:
        cout << "Grade level: B, exceeded expectations\n";
        break;
    case 7:
        cout << "Grade level: C, accept\n";
        break;
    case 6:
        cout << "Grade level: D, poor\n";
        break;
    default:
        cout << "Grade level: E, dreadful\n";
        break;
    }
    return 0; // 正常退出函数
}

int checkScholarship() {
    int grade;
    char isStuLeader;
    char isExcellentVolunteer;
    cout << "\n=== CHECK SCHOLARSHIP ===\n";

    cout << "Enter your grade (0-100): ";
    cin >> grade;
    if (grade > 100 || grade < 0) {
        return -1; // 带错误退出函数
    }

    cout << "Have you ever been a student leader? (Y/N): ";
    cin >> isStuLeader;
    isStuLeader = toupper(isStuLeader);
    if (isStuLeader != 'Y' && isStuLeader != 'N') {
        return -2; // 带错误退出函数
    }


    cout << "Have you ever attended the excellent volunteer activities? (Y/N): ";
    cin >> isExcellentVolunteer;
    isExcellentVolunteer = toupper(isExcellentVolunteer);
    if (isExcellentVolunteer != 'Y' && isExcellentVolunteer != 'N') {
        return -2; // 带错误退出函数
    }

    cout << "\n--- SCHOLARSHIP RESULT ---\n";
    cout << "Grade: " << grade << "\n";
    cout << "Student leader: " << (isStuLeader == 'Y' ? "Yes" : "No") << "\n";
    cout << "Excellent volunteer: " << (isExcellentVolunteer == 'Y' ? "Yes" : "No") << "\n";

    bool isEligible = false;
    string scholarType = "";

    if (grade >= 90) {
        isEligible = true;
        scholarType = "Excellent Grade"; // 成绩优异
    }
    else if (grade >= 80 && isStuLeader == 'Y') {
        isEligible = true;
        scholarType = "Student Leader"; // 学生干部
    }
    else if (grade >= 75 && isStuLeader == 'Y' && isExcellentVolunteer == 'Y') {
        isEligible = true;
        scholarType = "Comprehensive"; // 综合奖学金
    }
    else if (grade >= 70 && isExcellentVolunteer == 'Y') {
        isEligible = true;
        scholarType = "Volunteer"; // 优秀志愿者
    }
    else if (grade >= 60 && grade < 70) {
        char hasImproved;
        cout << "Compared to last term, have your grades improved significantly? (Y/N): ";
        cin >> hasImproved;
        hasImproved = toupper(hasImproved);
        if (hasImproved != 'Y' && hasImproved != 'N') {
            return -2; // 带错误退出函数
        }
        if (hasImproved == 'Y') {
            isEligible = true;
            scholarType = "Improvement"; // 成绩进步奖
        }
    }

    if (isEligible) {
        cout << "Congratulations! You are eligible for the " << scholarType << " scholarship.\n";
    }
    else {
        cout << "Sorry, you are not eligible for any scholarship this semester.\n";
    }
    return 0; // 正常退出函数
}

int showEvaluation() {
    int averageGrade;
    cout << "\n=== TERM EVALUATION ===\n";
    cout << "Enter your average grade for this term (0-100): ";
    cin >> averageGrade;
    if (averageGrade > 100 || averageGrade < 0) {
        return -1; // 带错误退出函数
    }
    switch (averageGrade / 10) {
    case 10:
    case 9:
        cout << "Level A\n";
        cout << "Overall Performance: OUTSTANDING\n";
        cout << "Feedback: You have demonstrated exceptional mastery of the course material.\n";
        cout << "Your consistent high performance sets a remarkable standard.\n";
        cout << "Suggestion: Consider taking on advanced projects or mentoring peers.\n";
        break;
    case 8:
        cout << "Level B\n";
        cout << "Overall Performance: VERY GOOD\n";
        cout << "Feedback: You have a strong grasp of the subject and consistently exceed expectations.\n";
        cout << "Suggestion: Focus on the few complex topics to reach the next level.\n";
        break;
    case 7:
        cout << "Level C\n";
        cout << "Overall Performance: SATISFACTORY\n";
        cout << "Feedback: You meet all core learning objectives. There is a solid foundation to build upon.\n";
        cout << "Suggestion: Increase revision time and actively participate in study groups.\n";
        break;
    case 6:
        cout << "Level D\n";
        cout << "Overall Performance: NEEDS IMPROVEMENT\n";
        cout << "Feedback: You have passed, but significant gaps in understanding are present.\n";
        cout <<
            "Suggestion: It is highly recommended to seek help from the instructor or a tutor, and review fundamentals.\n";
        break;
    default:
        cout << "Level E\n";
        cout << "Overall Performance: UNSATISFACTORY\n";
        cout << "Feedback: The current results indicate a major misunderstanding of the course content.\n";
        cout <<
            "Suggestion: Immediate action is required. Please schedule a meeting with your academic advisor to create a recovery plan.\n";
        break;
    }
    cout << "\n--- General Advice for Next Semester ---\n";
    cout << "1. Review your notes weekly, not just before exams.\n";
    cout << "2. Complete all assigned practice problems.\n";
    cout << "3. Don't hesitate to ask questions during lectures or office hours.\n";
    cout << "=========================================\n";
    return 0; // 正常退出函数
}

int use_grade() {
    int choice;

    while (true) {
        cout << "\nPlease select an action to perform(enter a number 1 - 4):\n";
        cout << "1. Check grade level\n";
        cout << "2. Determine if scholarship is awarded\n"; // 判断是否获得奖学金
        cout << "3. Show this semester's evaluation\n"; // 显示本学期评价
        cout << "4. Exit program\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            while (checkLevel() == -1) {
                // 重新调用函数让用户输入正确的成绩
                cerr << "Invalid grade. Please enter a number between 0 and 100.\n";
            }
            break;
        case 2:
            while (true) {
                int result = checkScholarship();
                if (result == 0) {
                    break; // 正常退出，跳出循环
                }
                else if (result == -1) {
                    cerr << "Invalid grade. Please enter a number between 0 and 100.\n";
                }
                else if (result == -2) {
                    cerr << "Invalid input for choice. Please enter Y or N.\n";
                }
            }
            break;
        case 3:
            while (showEvaluation() == -1) {
                // 重新调用函数让用户输入正确的成绩
                cerr << "Invalid average grade. Please enter a number between 0 and 100.\n";
            }
            break;
        case 4:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            cerr << "Invalid choice. Please enter a number between 1 and 4.\n";
            break;
        }
    }
}