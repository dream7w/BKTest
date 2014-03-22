/*==========================================
  @Author      : zabambo
  @File        : cpp_primer/tmain.cc
  @Encoding    : utf-8
  @Create      : 2014-03-22 00:33:29
  @Modified    : 2014-03-22 00:36:33
  @Description : 
==========================================*/

#include <stdio.h>
#include <stdlib.h>
#include "gtest_base.h"

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
