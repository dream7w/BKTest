/*==========================================
  @Author      : zabambo
  @File        : comm_def.h
  @Encoding    : utf-8
  @Create      : 2014-06-12 01:16:47
  @Modified    : 2014-07-03 20:25:13
  @Description : 
==========================================*/

#ifndef SRC_COMM_DEF_H_
#define SRC_COMM_DEF_H_

#include <stdio.h>
#include <stdlib.h>



/*
 *  brief   通用比较函数
 *  input   
 *  output  
 *  return
 */
template<class E>
int NormalCompare(const E &e1, const E &e2)
{
  if (e1 < e2) {
    return -1;
  }else if (e1 > e2){
    return 1;
  }
  return 0;
}

/*
 *  brief   通用输出数组函数
 */
template<class E>
void NormalPrint(const char *begin, E data[], int length, const char* end)
{
  printf("%s:", begin);
  for (int i = 0; i < length; ++i){
    printf("%d,", data[i]);
  }
  printf("%s\n:", end);
}





#endif//SRC_COMM_DEF_H_
