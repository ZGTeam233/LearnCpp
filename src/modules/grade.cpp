#include <iostream>
#include <cctype>
#include <string>

int checkLevel() {
	int grade;
	std::cout << "\n=== CHECK LEVEL ===\n";
	std::cout << "Enter your grade (0-100): ";
	std::cin >> grade;
	if (grade > 100 || grade < 0) {
		return -1; // 带错误退出函数
	}
	switch (grade / 10) {
	case 10:
	case 9:
		std::cout << "Grade level: A, outstanding\n";
		break;
	case 8:
		std::cout << "Grade level: B, exceeded expectations\n";
		break;
	case 7:
		std::cout << "Grade level: C, accept\n";
		break;
	case 6:
		std::cout << "Grade level: D, poor\n";
		break;
	default:
		std::cout << "Grade level: E, dreadful\n";
		break;
	}
	return 0; // 正常退出函数
}

int checkScholarship() {
	int grade;
	char isStuLeader;
	char isExcellentVolunteer;
	std::cout << "\n=== CHECK SCHOLARSHIP ===\n";

	std::cout << "Enter your grade (0-100): ";
	std::cin >> grade;
	if (grade > 100 || grade < 0) {
		return -1; // 带错误退出函数
	}

	std::cout << "Have you ever been a student leader? (Y/N): ";
	std::cin >> isStuLeader;
	isStuLeader = toupper(isStuLeader);
	if (isStuLeader != 'Y' && isStuLeader != 'N') {
		return -2; // 带错误退出函数
	}

	
	std::cout << "Have you ever attended the excellent volunteer activities? (Y/N): ";
	std::cin >> isExcellentVolunteer;
	isExcellentVolunteer = toupper(isExcellentVolunteer);
	if (isExcellentVolunteer != 'Y' && isExcellentVolunteer != 'N') {
		return -2; // 带错误退出函数
	}

	std::cout << "\n--- SCHOLARSHIP RESULT ---\n";
	std::cout << "Grade: " << grade << "\n";
	std::cout << "Student leader: " << (isStuLeader == 'Y' ? "Yes" : "No") << "\n";
	std::cout << "Excellent volunteer: " << (isExcellentVolunteer == 'Y' ? "Yes" : "No") << "\n";
	
	bool isEligible = false;
	std::string scholarType = "";

	if (grade >= 90) {
		isEligible = true;
		scholarType = "Excellent Grade"; // 成绩优异
	} else if (grade >= 80 && isStuLeader == 'Y') {
		isEligible = true;
		scholarType = "Student Leader"; // 学生干部
	} else if (grade >= 75 && isStuLeader == 'Y' && isExcellentVolunteer == 'Y') {
		isEligible = true;
		scholarType = "Comprehensive"; // 综合奖学金
	} else if (grade >= 70 && isExcellentVolunteer == 'Y') {
		isEligible = true;
		scholarType = "Volunteer"; // 优秀志愿者
	} else if (grade >= 60 && grade < 70) {
		char hasImproved;
		std::cout << "Compared to last term, have your grades improved significantly? (Y/N): ";
		std::cin >> hasImproved;
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
		std::cout << "Congratulations! You are eligible for the " << scholarType << " scholarship.\n";
	} else {
		std::cout << "Sorry, you are not eligible for any scholarship this semester.\n";
	}
	return 0; // 正常退出函数
}

int showEvaluation() {
	int averageGrade;
	std::cout << "\n=== TERM EVALUATION ===\n";
	std::cout << "Enter your average grade for this term (0-100): ";
	std::cin >> averageGrade;
	if (averageGrade > 100 || averageGrade < 0) {
		return -1; // 带错误退出函数
	}
	switch (averageGrade / 10) {
	case 10:
	case 9:
		std::cout << "Level A\n";
		std::cout << "Overall Performance: OUTSTANDING\n";
		std::cout << "Feedback: You have demonstrated exceptional mastery of the course material.\n";
		std::cout << "Your consistent high performance sets a remarkable standard.\n";
        std::cout << "Suggestion: Consider taking on advanced projects or mentoring peers.\n";
		break;
	case 8:
		std::cout << "Level B\n";
		std::cout << "Overall Performance: VERY GOOD\n";
		std::cout << "Feedback: You have a strong grasp of the subject and consistently exceed expectations.\n";
        std::cout << "Suggestion: Focus on the few complex topics to reach the next level.\n";
		break;
	case 7:
		std::cout << "Level C\n";
		std::cout << "Overall Performance: SATISFACTORY\n";
		std::cout << "Feedback: You meet all core learning objectives. There is a solid foundation to build upon.\n";
        std::cout << "Suggestion: Increase revision time and actively participate in study groups.\n";
		break;
	case 6:
		std::cout << "Level D\n";
		std::cout << "Overall Performance: NEEDS IMPROVEMENT\n";
		std::cout << "Feedback: You have passed, but significant gaps in understanding are present.\n";
        std::cout << "Suggestion: It is highly recommended to seek help from the instructor or a tutor, and review fundamentals.\n";
		break;
	default:
		std::cout << "Level E\n";
		std::cout << "Overall Performance: UNSATISFACTORY\n";
		std::cout << "Feedback: The current results indicate a major misunderstanding of the course content.\n";
        std::cout << "Suggestion: Immediate action is required. Please schedule a meeting with your academic advisor to create a recovery plan.\n";
		break;
	}
	std::cout << "\n--- General Advice for Next Semester ---\n";
    std::cout << "1. Review your notes weekly, not just before exams.\n";
    std::cout << "2. Complete all assigned practice problems.\n";
    std::cout << "3. Don't hesitate to ask questions during lectures or office hours.\n";
    std::cout << "=========================================\n";
	return 0; // 正常退出函数
}
