#include "ros.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(RosTest, ReadFile)
{
  readFile("");
  EXPECT_TRUE(readFile(""));
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
