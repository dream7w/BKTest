/*==========================================
  @Author      : zabambo
  @File        : src/time.cc
  @Encoding    : utf-8
  @Create      : 2014-06-15 23:19:13
  @Modified    : 2014-06-15 23:37:08
  @Description : linux时间API
==========================================*/

#include <time.h> 
#include "time.h"

void TestTime()
{
  TTime::TestClock();
}


void TTime::TestClock()
{
  clock_t start = clock();
  sleep(10);
  clock_t end = clock();
  //CLOCKS_PER_SEC 一钞钟的cpu时钟计时单元
  printf("start:%d, end:%d, second:%d", start, end, (int)((start - end) / CLOCKS_PER_SEC) );
}

