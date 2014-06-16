/*==========================================
  @Author      : zabambo
  @File        : src/ttime.h
  @Encoding    : utf-8
  @Create      : 2014-06-15 23:18:54
  @Modified    : 2014-06-16 17:22:58
  @Description : linux时间API
==========================================*/

#ifndef SRC_TTIME_H_
#define SRC_TTIME_H_

#include "comm_def.h"
#include <time.h> 
#include <sys/time.h> 
#include <sys/timeb.h> 
#include <sys/times.h> 



void TestTime();

class TTime
{
  public:
    static void TestClock();
    static void TestTimeS();
    static void TestTime();
    static void PrintTM(struct tm *tm_time);

};


#endif//SRC_TTIME_H_
