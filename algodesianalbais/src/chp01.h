/*==========================================
  @Author      : zabambo
  @File        : src/chp01.h
  @Encoding    : utf-8
  @Create      : 2014-07-07 20:14:00
  @Modified    : 2014-07-08 15:33:46
  @Description : 
==========================================*/

#ifndef SRC_CHP01_H_
#define SRC_CHP01_H_

#include <stdio.h>
#include <stdlib.h>


//欧几里得最大公约数---求模法
int gcd(int a, int b);
//欧几里得最大公约数---减法
int gcdsub(int a, int b);

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



void TestCHP01();

#endif//SRC_CHP01_H_
