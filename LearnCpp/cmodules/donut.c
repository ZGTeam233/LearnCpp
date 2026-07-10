//
// Copyright(c) 2025 ZGTeam233.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../ccore.h"

int k = 0;
double sin(), cos();

void donut() {
    double A = 0, B = 0, z[1760];
    char b[1760];
    
    printf("\x1b[2J");  // 清屏
    
    while (1) {
        memset(b, 32, 1760);  // 用空格填充
        memset(z, 0, 7040);   // 深度缓冲清零
        
        for (double j = 0; j < 6.28; j += 0.07) {          // theta
            for (double i = 0; i < 6.28; i += 0.02) {      // phi
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;
                
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                
                if (y > 0 && y < 22 && x > 0 && x < 80 && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        
        printf("\x1b[H");  // 光标回到左上角
        for (k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);  // 每80个字符换行
        }
        
        A += 0.04;
        B += 0.02;
    }
}