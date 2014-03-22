/*==========================================
  @Author      : zabambo
  @File        : cpp_primer/t01_01.cc
  @Encoding    : utf-8
  @Create      : 2014-03-22 00:33:04
  @Modified    : 2014-03-22 00:45:47
  @Description : 
==========================================*/

#include "t01_01.h"



#if 0
void t01_01_using(string &str)
#else
using std::string;
void t01_01_using(string &str)
#endif
{
  if (str.empty()){
    return;
  }
}

