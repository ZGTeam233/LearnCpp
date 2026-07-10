// Created by wsnzg6 on 2026/7/10.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "test.h"

using namespace std;

void test1() {
    // 原始成绩
    vector<int> scores = {45, 88, 59, 72, 95, 60, 30, 82};
    // 外部变量：平时加分
    int bonus = 5;
    vector<int> passed_scores;
    copy_if(scores.begin(),
        scores.end(),
        back_inserter(passed_scores),
        [](int score) {
            return score >= 60;
        });

    transform(passed_scores.begin(),
        passed_scores.end(),
        passed_scores.begin(),
        [bonus](int score) {
            return min(bonus + score, 100);
        });

    sort(passed_scores.begin(),
        passed_scores.end(),
        [](int score1, int score2) {
            return score1 > score2;
        });

    // 打印最终结果
    cout << "最终成绩: ";
    for (int score : passed_scores) {
        cout << score << " ";
    }
    cout << endl;
}
