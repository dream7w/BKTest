/*==========================================
  @Author      : zabambo
  @File        : src/chp01.cc
  @Encoding    : utf-8
  @Create      : 2014-07-07 20:13:58
  @Modified    : 2014-07-08 15:44:38
  @Description : 
==========================================*/
#include "chp01.h"

void TestCHP01()
{
  printf("%d\n", gcd(1000,499));
  printf("%d\n", gcdsub(1000,499));
}

int gcd(int a, int b)
{
  int c = 0;
  while(b){
    c = a % b;
    a = b; 
    b = c;
  }
  return a;
}

int gcdsub(int a, int b)
{
  int c = a;
  while(b){
    if (a < b){
      c = a;
      a = b;
      b = c;
    }
    c = a - b;
    a = b;
    b = c;
  }
  return a;
}

bool GcdGame(int a, int b)
{
  int c = gcd(a, b);
  int cnt = a / c;
  return (cnt % 2 > 0);
}


