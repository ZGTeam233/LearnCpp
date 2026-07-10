//
// Created by wsnzg6 on 2026/6/19.
// Copyright(c) 2026 ZGTeam233.
//

#include <stdio.h>
#include "ccore.h"

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

int main () {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif // _WIN32

    printf("\n这个主程序是专门C语言的\n");
    printf("请选择打开的项目\n");
    printf("\t1. 圆的计算\n");
    printf("\t2. 判断质数\n");
    printf("\t3. 三角函数\n");
    printf("\t4. ASCII甜甜圈\n");
    printf("\t5. 猜数字游戏\n");
    printf("\t0. 退出\n");
    printf("请选择：");
    int choice = 0;
    scanf("%d", &choice);
    switch (choice) {
        case 1: circle(); break;
        case 2: prime(); break;
        case 3: trifx(); break;
        case 4: donut(); break;
        case 5: guess(); break;
        default: break;
    }
    return 0;
}