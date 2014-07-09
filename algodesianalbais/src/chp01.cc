/*==========================================
  @Author      : zabambo
  @File        : src/chp01.cc
  @Encoding    : utf-8
  @Create      : 2014-07-07 20:13:58
  @Modified    : 2014-07-09 15:03:28
  @Description : 
==========================================*/
#include "chp01.h"

void TestCHP01()
{
#if 0
  printf("%d\n", Gcd(1000,499));
  printf("%d\n", GcdSub(1000,499));
  int a=3,b=2,d=0,x,y;
  ExtGcdRecu(a, b, d, x, y);
  printf("a:%d, b:%d, d:%d, x:%d, y:%d\n", a, b, d, x, y);
#endif
  ThePeasantProgram();
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
/*
  int x1,y1,x0,y0;
  x0=1; y0=0;
  x1=0; y1=1;
  x=0; y=1;
  int r=m%n;
  int q=(m-r)/n;
  while(r)
  {
      x=x0-q*x1; y=y0-q*y1;
      x0=x1; y0=y1;
      x1=x; y1=y;
      m=n; n=r; r=m%n;
      q=(m-r)/n;
  }
  return n;  
*/
}

int TheLockedDoor(int n)
{
  if (n < 1){return 0;}
  int r = sqrt(n);
  for (int i = 1; i <= r; ++i){
    int d = i * i;//the Open Doors
  }

  return r;
}

void ThePeasantProgram()
{
#define w 3
#define s 2
#define g 1
#define N 3
  int side[2][N]={w,s,g, 0,0,0};
  int cnt = 0;
  int id = 0;
  int last_id = -1;
  printf("%d %d %d --- %d %d %d\n", side[0][0], side[0][1], side[0][2] , side[1][0], side[1][1], side[1][2]);
  while(true){
    id =cnt % 2;
    int i = 0;
    int cur_id = -1;
    while(i < N -1){
      if (side[id][i] > 0 && side[id][i+1] > 0){
        if (last_id != i+1){
          cur_id = i+1;
          break;
        }
      }
      ++i;
    }
    if (cur_id < 0 && id == 0){
      i = 0;
      while(i < N && side[id][i] == 0){++i;}
      cur_id = i;
    }

    if (cur_id >= 0){
      last_id = cur_id;
      side[(id + 1) % 2][last_id] = side[id][last_id];
      side[id][last_id] = 0;
    }else{
      last_id = -1;
    }
    i = 0;
    while(i < N && side[0][i] == 0){i++;}
    printf("%d %d %d --- %d %d %d\n", side[0][0], side[0][1], side[0][2] , side[1][0], side[1][1], side[1][2]);
    if (i == N){return;}
    ++cnt;
  }

}



