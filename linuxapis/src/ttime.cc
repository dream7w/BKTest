/*==========================================
  @Author      : zabambo
  @File        : src/ttime.cc
  @Encoding    : utf-8
  @Create      : 2014-06-15 23:19:13
  @Modified    : 2014-06-16 17:51:44
  @Description : linux时间API
==========================================*/

#include <unistd.h>
#include "ttime.h"

void TestTime()
{
  TTime::TestClock();
  TTime::TestTimeS();
  TTime::TestTime();
}
void TTime::TestClock()
{
  printf("\ntest clock()\n");
  clock_t start = ::clock();
  for (long i = 0; i < 100; ++i){
    printf("count:%ld", i);
  }
  sleep(3); //**********************************sleep不占用cpu时间
  clock_t end = ::clock();
  //CLOCKS_PER_SEC 一钞钟的cpu时钟计时单元
  printf("start:%lu, end:%ld, diff:%ld, second:%f\n", (unsigned long)start, (long)end, (end - start), (double)((end - start) / CLOCKS_PER_SEC) );
}

void TTime::TestTimeS()
{
  printf("\ntest times()\n");
  struct tms tmp;
  clock_t start = ::times(&tmp);
  for (long i = 0; i < 100; ++i){
    printf("count:%ld", i);
  }
  sleep(3); //**********************************sleep占用实际运行时间
  clock_t end = ::times(&tmp);
  printf("start:%lu, end:%ld, diff:%ld, second:%f\n", (unsigned long)start, (long)end, (end - start), (double)((end - start) / sysconf(_SC_CLK_TCK)) );
}

void TTime::TestTime()
{
  printf("\ntest time()\n");
  time_t start = ::time(NULL);
  printf("start time second:%ld\n", (long)start);

  printf("\ngmtime_r():\n");
  struct tm tm_time;
  gmtime_r(&start, &tm_time);
  PrintTM(&tm_time);

  printf("\nlocaltime_r():\n"); //要先设置本地时区才有正确的本地时间
  localtime_r(&start, &tm_time);
  PrintTM(&tm_time);

  printf("\nmktime():\n");
  time_t make_time = mktime(&tm_time);
  printf("make_time:%ld\n", make_time);
  PrintTM(&tm_time);

  printf("\ngettimeofday():\n");
  struct timeval tv; 
  struct timezone tz;
  gettimeofday(&tv, &tz);
  printf("timeval.tv_sec:%ld, timeval.tv_usec:%ld\n", tv.tv_sec, tv.tv_usec);
  printf("timezone.tz_minuteswest:%d, timeval.tz_dsttime:%d\n", tz.tz_minuteswest, tz.tz_dsttime);

  printf("\nftime():\n");
  struct timeb tb;
  ftime(&tb);
  printf("timeb.time:%ld\n", tb.time);
  printf("timeb.millitm:%d\n", tb.millitm);
  printf("timeb.timezone:%d\n", tb.timezone);
  printf("timeb.dstflag:%d\n", tb.dstflag);

  printf("\nclock_gettime():\n");
  struct timespec tp;
  clock_gettime(CLOCK_MONOTONIC, &tp);
  printf("timespec.tv_sec:%ld\n", tp.tv_sec);
  printf("timespec.tv_nsec:%ld\n", tp.tv_nsec);
 
  
  printf("\nasctime():\n");
  printf("asctime:%s\n", asctime(&tm_time));
  printf("\nctime():\n");
  printf("ctime:%s\n", ctime(&start));
  

  printf("\nstrftime():\n");
  char sztime[64] = {'\0'};
  strftime(sztime, sizeof(sztime), "%Y-%m-%d %H:%M:%S", &tm_time);
  printf("strftime:%s\n", sztime);

}

void TTime::PrintTM(struct tm *tm_time)
{
  if (NULL == tm_time){
    return;
  }
  printf("tm:\n");
#define P(A)\
  printf("tm_%s:%d\n", #A, tm_time->tm_##A);
  
  P(sec);
  P(min);
  P(hour);
  P(mday);
  P(mon);
  P(year);
  P(wday);
  P(yday);
  P(isdst);
#undef P
}



