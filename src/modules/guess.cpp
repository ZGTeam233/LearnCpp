#include <iostream>
#include <vector>
#include "../core.h"

using namespace std;

// GOD, HOPE IT THIS CODE WORKS FINE NOW.
void guess() {
    int guess = 0;
    int attempts = 0; // 猜测次数
    vector<int> password = { 42, 15, 7, 93, 28 }; // 猜数字游戏答案
    int round = 0; // 当前轮数
    int choice;
    cout << "Welcome to the Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Can you guess what it is ?" << endl;
    cout << "You have seven attempts to guess the correct number." << endl;
    while (guess != password[round]) {
        if (attempts < 7) {
            // 允许猜测
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess < password[round]) {
                cout << "Too low! Try again." << endl; // 猜测过低
            } else if (guess > password[round]) {
                cout << "Too high! Try again." << endl; // 猜测过高
            } else {
                // 猜测正确
                cout << "Congratulations! You've guessed the correct number: "
                        << password[round] << "." << endl;
                if (round == 4) {
                    // 完成所有轮次
                    cout << "You've completed all rounds! Well done!" << endl;
                    break;
                }
                else {
                    // 询问是否继续下一轮
                    cout << "Wanna try the next number? Input 1 to continue or 0 to quit: " << endl;
                    cin >> choice;
                    if (choice == 1) {
                        // 继续下一轮
                        round++;
                        attempts = 0;
                        guess = 0;
                    }
                    else {
                        // 退出游戏
                        cout << "Thanks for playing! Goodbye!" << endl;
                        break;
                    }
                }
            }
        }
        else {
            // 超过七次未猜中
            cout << "Sorry, you've used all your attempts. The correct number was "
                    << password[round] << "." << endl;
            break;
        }
    }
}