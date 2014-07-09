/*==========================================
  @Author      : zabambo
  @File        : src/chp01.h
  @Encoding    : utf-8
  @Create      : 2014-07-07 20:14:00
  @Modified    : 2014-07-09 14:42:58
  @Description : 
==========================================*/

#ifndef SRC_CHP01_H_
#define SRC_CHP01_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
定理：gcd(a,b) = gcd(b,a mod b) 
证明：a可以表示成a = kb + r，则r = a mod b 
假设d是a,b的一个公约数，则有d|a, d|b，而r = a - kb，因此d|r 
因此d是(b,a mod b)的公约数 
假设d 是(b,a mod b)的公约数，则d | b , d |r ，但是a = kb +r 
因此d也是(a,b)的公约数 
因此(a,b)和(b,a mod b)的公约数是一样的，其最大公约数也必然相等，得证。 
*/
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
　　根据【恒等定理】得：x1=y2; y1=x2-(a/b)*y2;
     这样我们就得到了求解 x1,y1 的方法：x1，y1 的值基于 x2，y2.
　  上面的思想是以递归定义的，因为 gcd 不断的递归求解一定会有个时候 b=0，所以递归可以结束。
*/
//递归算法，完成
void ExtGcdRecu(int a, int b, int &d, int &x, int &y);
//非递归算法，未完成
void ExtGcdNoRecu(int a, int b, int &d, int &x, int &y);


/*
提出问题：
在走廊上有n个带锁的门，从1到n一次编号。最初所有的门都是关着的。
我们从门前一次经过n此，每一次都从1号门开始。
在第i次经过时（i = 1，2．．．n）我们改变i的整数倍号锁的状态：
也就是如果们是关着的，就打开它；如果门是打开的，就关上它。
举例来说，第一次经过之后，所有的门都是打开的；
第二次经过时，我们只改变偶数门得状态（2号门，4号门．．．．．．）
这样一来，第二次经过之后，偶数门是关着的，而奇数门是开着的；
第三次经过时，我们把3号门关上（该门在第一次经过时被打开），
打开6号门（该门在第二次经过时被关上），以此类推。
在最后以此经过后，那些门是打开的？那些门是关上的？有多少打开的门？
*/
int TheLockedDoor(int n);

/*
一个人,一只狼,一只山羊,一担青草,要过河,
可是只有一只小船, 一次只能装一个人和其他三种中的一种,
请问应该怎样过河, 人不在的时候,狼会吃羊,羊会吃草.
*/
void ThePeasantProgram();









void TestCHP01();

#endif//SRC_CHP01_H_
