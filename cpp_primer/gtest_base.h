/*==========================================
  @Author      : zabambo
  @File        : cpp_primer/gtest_base.h
  @Encoding    : utf-8
  @Create      : 2014-03-22 00:34:02
  @Modified    : 2014-03-22 00:36:05
  @Description : 
==========================================*/
#ifndef CPPPRIMER_GTEST_BASE_H_
#define CPPPRIMER_GTEST_BASE_H_

#include "gtest/gtest.h"

class GTTest : public ::testing::Test
{
  protected:
    static void SetUpTestCase(){}
    static void TearDownTestCase(){}

    virtual void SetUp(){}
    virtual void TearDown(){}
};

/*
TEST_F(GTTest, Foo)
{
  ASSERT_TRUE(1 == 1);
}
*/



#endif//CPPPRIMER_GTEST_BASE_H_

