#include <stdio.h>
#include <math.h>
#include "../ccore.h"

void circle() {
    double radius;
    printf("中文显示测试\n");
    printf("Please enter the radius of the circle: ");
    scanf("%lf", &radius);
    double circumference = 2 * PI * radius;
    double square = PI * radius * radius;
    printf("The circumference of the circle is: %.2f\n", circumference);
    printf("The area of the circle is: %.2f\n", square);
}

//判断质数逻辑
int isPrime(const int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void prime() {
    //输入两个数
    int m;
    int n;
    printf("Please enter two numbers.\nThe first number must be less than or equal to the second number.\nEnter first number: ");
    scanf("%d", &m);
    printf("Enter second number: ");
    scanf("%d", &n);

    //防崩溃
    if (m > n) {
        printf("ERROR!\nThe numbers must less than or equal to the numbers.\n");
        return;
    }
    if (n - m > 511) {
        printf("ERROR!\nTooooo long!\n0");
        return;
    }

    //判断与输出
    for (int j = m; j <= n; j++) {
        if (isPrime(j)) {
            printf("%d is a prime number.\n", j);
        }
    }
}

// trifx 指 triangular function
// tri 取自 triangular
// fx 在数学里指 function

void trifx() {
    //初始化 initialization
    const double cos0 = sqrt(1 - SIN0 * SIN0);
    const double tan0 = SIN0 / cos0;
    const double deg0 = 1.0 / 60.0;
    printf("Minute = 1\n");
    printf("Degree(1') = %.6f\n", deg0);
    printf("Sine(1') = %.4f\n", SIN0);
    printf("Cosine(1') = %.4f\n", cos0);
    printf("Tangent(1') = %.4f\n", tan0);
    double sine = SIN0;
    double cosine = cos0;

    //角度的倍数 multiple of the angle
    int n=2;
    do {
        //计算 calculate
        sine = SIN0 * cosine + cos0 * sine;
        cosine = sqrt(1 - sine * sine);
        double tangent = sine / cosine;
        double degree = n / 60.0;
        printf("Minute = %d\n", n);
        printf("Degree(%d') = %.4f\n", n, degree);
        printf("Sine(%d') = %.4f\n", n, sine);
        printf("Cosine(%d') = %.4f\n", n, cosine);
        printf("Tangent(%d') = %.4f\n", n, tangent);
        printf("---------------\n");
        printf("\n");
        n++;
    } while (n <= 5400);
}

