/*==========================================
  @Author      : zabambo
  @File        : src/chp01.cc
  @Encoding    : utf-8
  @Create      : 2014-07-07 20:13:58
  @Modified    : 2014-07-08 14:57:07
  @Description : 
==========================================*/
#include "chp01.h"

void TestCHP01()
{
  printf("%d\n", gcd(1000,100));
}

int gcd(int a, int b)
{
  printf("a:%d, b:%d\n", a, b);
  int c = 0;
  while((c = a % b) > 0){
    a = b; 
    b = c;
    printf("a:%d, b:%d\n", a, b);
  }
  return b;
}
