# 免责声明

---
### Sales 版权与免责声明
本文件夹，包含来自《C++ Primer 第5版》的代码，

作者为 *Stanley B. Lippman*、*Josee Lajoie* 和 *Barbara E. Moo*，

并遵循该书中给出的版权和保修声明：

“Copyright(c) 2013，Objectwrite, Inc., Josee Lajoie, 和 Barbara E. Moo。”

“作者和出版商在准备本书时已尽力，但不作任何明示或暗示的保证，并不对错误或疏漏承担任何责任。

对于使用本文所含信息或程序而产生的偶然或后续损害概不负责。”

允许将此代码用于与本书相关的教育用途，如在发布或复制时给出适当引用。

任何商业用途需要出版商 Addison-Wesley Professional（Pearson 教育公司的一部分）明确书面许可。

请将您的许可请求发送至以下地址，明确说明希望使用的代码及具体使用方式：

```
Pearson 教育公司 权利与许可部门
One Lake Street, Upper Saddle River, NJ 07458
传真: (201) 236-3290
```

---
#### 英文原文如下 English
This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
copyright and warranty notices given in that book:

"Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."

"The authors and publisher have taken care in the preparation of this book,
but make no expressed or implied warranty of any kind and assume no
responsibility for errors or omissions. No liability is assumed for
incidental or consequential damages in connection with or arising out of the
use of the information or programs contained herein."

Permission is granted for this code to be used for educational purposes in
association with the book, given proper citation if and when posted or
reproduced.Any commercial use of this code requires the explicit written
permission of the publisher, Addison-Wesley Professional, a division of
Pearson Education, Inc. Send your request for permission, stating clearly
what code you would like to use, and in what specific way, to the following
address:
```
Pearson Education, Inc.
Rights and Permissions Department
One Lake Street
Upper Saddle River, NJ  07458
Fax: (201) 236-3290
```

---
### donut 免责声明

经典 *ASCII* 甜甜圈的 *C语言*实现，最初由 *Andy Sloane* 于 2011 年创建。

A *C* implementation of the classic *ASCII* donut, originally created by *Andy Sloane* in 2011.

这个程序使用了简单的数学函数来计算甜甜圈的形状，并通过 *ASCII* 字符在终端上显示出来。

The program uses simple mathematical functions to calculate the shape of the donut and displays it in the terminal using *ASCII* characters.

这里为源码，在这里仅为学习参考引用，我也***并非原作者***，原帖地址：[https://www.a1k0n.net/2011/07/20/donut-math.html](https://www.a1k0n.net/2011/07/20/donut-math.html)

The source code is provided here for learning reference, and I am ***not the original author***. The original post can be found at: [https://www.a1k0n.net/2011/07/20/donut-math.html](https://www.a1k0n.net/2011/07/20/donut-math.html)

源代码如下 Following is the source code

```c
              k;double sin()
          ,cos();main(){float A=
        0,B=0,i,j,z[1760];char b[
      1760];printf("\x1b[2J");for(;;
   ){memset(b,32,1760);memset(z,0,7040)
   ;for(j=0;6.28>j;j+=0.07)for(i=0;6.28
  >i;i+=0.02){float c=sin(i),d=cos(j),e=
  sin(A),f=sin(j),g=cos(A),h=d+2,D=1/(c*
  h*e+f*g+5),l=cos      (i),m=cos(B),n=s\
 in(B),t=c*h*g-f*        e;int x=40+30*D*
 (l*h*m-t*n),y=            12+15*D*(l*h*n
 +t*m),o=x+80*y,          N=8*((f*e-c*d*g
  )*m-c*d*e-f*g-l        *d*n);if(22>y&&
  y>0&&x>0&&80>x&&D>z[o]){z[o]=D;;;b[o]=
  ".,-~:;=!*#$@"[N>0?N:0];}}/*#****!!-*/
   printf("\x1b[H");for(k=0;1761>k;k++)
    putchar(k%80?b[k]:10);A+=0.04;B+=
      0.02;}}/*****####*******!!=;:~
        ~::==!!!**********!!!==::-
          .,~~;;;========;;;:~-.
              ..,--------,*/
```