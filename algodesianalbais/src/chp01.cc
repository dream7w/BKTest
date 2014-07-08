/*==========================================
  @Author      : zabambo
  @File        : src/chp01.cc
  @Encoding    : utf-8
  @Create      : 2014-07-07 20:13:58
  @Modified    : 2014-07-08 16:53:18
  @Description : 
==========================================*/
#include "chp01.h"

void TestCHP01()
{
  printf("%d\n", Gcd(1000,499));
  printf("%d\n", GcdSub(1000,499));
  int a=3,b=2,d=0,x,y;
  ExtGcdRecu(a, b, d, x, y);
  printf("a:%d, b:%d, d:%d, x:%d, y:%d\n", a, b, d, x, y);
  
}

int Gcd(int a, int b)
{
  int c = 0;
  if (a < b){
    c = a;
    a = b;
    b = c;
  }
  while(b){
    c = a % b;
    a = b; 
    b = c;
  }
  return a;
}

int GcdSub(int a, int b)
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
  int c = Gcd(a, b);
  int cnt = a / c;
  return (cnt % 2 > 0);
}

void ExtGcdRecu(int a, int b, int &d, int &x, int &y)
{
  if (0 == b){
    x = 1;
    y = 0;
    d = a;
    return;
  }
  ExtGcdRecu(b, a % b, d, x, y);
  int t = x;
  x = y;
  y = t - a/b * y;
}

void ExtGcdNoRecu(int a, int b, int &d, int &x, int &y)
{
  
}

