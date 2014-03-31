/*==========================================
  @Author      : zabambo
  @File        : cpp_primer/t01_01.h
  @Encoding    : utf-8
  @Create      : 2014-03-22 00:32:18
  @Modified    : 2014-03-22 00:50:08
  @Description : 
==========================================*/

#ifndef CPPPRIMER_T01_01_H_
#define CPPPRIMER_T01_01_H_

#include <string>
#include <iostream>
#include "gtest_base.h"

#if 0
using std::string;
void t01_01_using(string &str);
#else
void t01_01_using(std::string &str);
#endif


TEST_F(GTTest, StdIo)
{
  std::string str;
  while (std::cin >> str){
    printf("%s\n", str.c_str());
  }
}


#endif//CPPPRIMER_T01_01_H_
