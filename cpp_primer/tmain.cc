#include <stdio.h>
#include <stdlib.h>
#include "gtest/gtest.h"

class GTTest : public ::testing::Test
{
  protected:
    static void SetUpTestCase(){}
    static void TearDownTestCase(){}

    virtual void SetUp(){}
    virtual void TearDown(){}
};

TEST_F(GTTest, Foo)
{
  ASSERT_TRUE(1 == 1);
}

int main(int argc, char **argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
