/*==========================================
  @Author      : zabambo
  @File        : src/chp01.h
  @Encoding    : utf-8
  @Create      : 2014-07-07 20:14:00
  @Modified    : 2014-07-08 17:11:06
  @Description : 
==========================================*/

#ifndef SRC_CHP01_H_
#define SRC_CHP01_H_

#include <stdio.h>
#include <stdlib.h>


//欧几里得最大公约数---求模法
int Gcd(int a, int b);
//欧几里得最大公约数---减法
int GcdSub(int a, int b);

/*
欧几里得游戏:
一开始，板上写有2个不相等的正整数。2个玩家交替写数字，
每一次，当前玩家都必须在板上写出任意2个板上数字的差，
而且这个数字必须是新的，也就是说，不能与板上任何一个已有的数字相同。
当玩家再也写不出新数字时，他就输了。请问 你是选择先行动还是后行动？

数学模型：
设最初两个数较大的为a, 较小的为b，两个数的最大公约数为c。
则最终能出现的数包括:c, c*2, c*3, ..., c*(a/c)=a. 一共a/c个。
如果a/c是奇数，就选择先行动；否则就后行动
*/
//返回true先行动
bool GcdGame(int a, int b);

/*
扩展欧几里得算法
对于不完全为 0 的非负整数 a，b，d表示 a，b 的最大公约数，
必然存在整数对 x，y ，使得 d=ax+by。

证明：设 a>b。
1，显然当 b=0，gcd（a，b）=a。此时 x=1，y=0；
2，ab!=0 时
　　设 ax1+by1=gcd(a,b);
　　bx2+(a mod b)y2=gcd(b,a mod b);
　　根据朴素的欧几里德原理有 gcd(a,b)=gcd(b,a mod b);
　　则:ax1+by1=bx2+(a mod b)y2;
　　即:ax1+by1=bx2+(a-(a/b)*b)y2=ay2+bx2-(a/b)*by2;
　　根据恒等定理得：x1=y2; y1=x2-(a/b)*y2;
     这样我们就得到了求解 x1,y1 的方法：x1，y1 的值基于 x2，y2.
　  上面的思想是以递归定义的，因为 gcd 不断的递归求解一定会有个时候 b=0，所以递归可以结束。
*/
//递归算法，完成
void ExtGcdRecu(int a, int b, int &d, int &x, int &y);
//非递归算法，未完成
void ExtGcdNoRecu(int a, int b, int &d, int &x, int &y);


void TestCHP01();

#endif//SRC_CHP01_H_
