//
// Copyright(c) 2025 ZGTeam233.
//

#include <stdio.h>
#include "../ccore.h"

void guess() {
    int guess = 0;
    int attempts = 0; // 猜测次数
    const int password[5] = {42, 15, 7, 93, 28}; // 猜数字游戏答案
    int round = 0; // 当前轮数
    int choice;

    printf("Welcome to the Guessing Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("Can you guess what it is?\n");
    printf("You have seven attempts to guess the correct number.\n");

    while (guess != password[round]) {
        if (attempts < 7) {
            // 允许猜测
            printf("Enter your guess: ");
            scanf("%d", &guess);
            attempts++;

            if (guess < password[round]) {
                printf("Too low! Try again.\n"); // 猜测过低
            }
            else if (guess > password[round]) {
                printf("Too high! Try again.\n"); // 猜测过高
            }
            else {
                // 猜测正确
                printf("Congratulations! You've guessed the correct number: %d\n", password[round]);
                if (round == 4) {
                    // 完成所有轮次
                    printf("You've completed all rounds! Well done!\n");
                    break;
                }
                else {
                    // 询问是否继续下一轮
                    printf("Wanna try the next number? Input 1 to continue or 0 to quit: ");
                    scanf("%d", &choice);
                    if (choice == 1) {
                        // 继续下一轮
                        round++;
                        attempts = 0;
                        guess = 0;
                    }
                    else {
                        // 退出游戏
                        printf("Thanks for playing! Goodbye!\n");
                        break;
                    }
                }
            }
        }
        else {
            // 超过七次未猜中
            printf("Sorry, you've used all your attempts. The correct number was %d.\n", password[round]);
            break;
        }
    }
}
