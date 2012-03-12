// ros includes
#include "RosEntry.h"
#include "RosEntryFactory.h"

// gtest
#include <gtest/gtest.h>

// std lib
#include <string>
#include <vector>
#include <sstream>


using namespace ros;

TEST(Ros, RosEntry)
{
  std::string name = "EntryName";
  int soldMonth = 12;
  double proInc = 123.4567;
  
  RosEntry entry(name, soldMonth, proInc);
  EXPECT_TRUE( entry.getName() == name );
  EXPECT_TRUE( entry.getSoldMonth() == soldMonth );
  EXPECT_TRUE( entry.getProjectedIncome() == proInc );

  // end up false
  EXPECT_TRUE( entry.getName() != "ASADASD" );
}

TEST(Ros, RosEntryFactory)
{
  std::string name = "EntryName";
  int soldMonth = 12345;
  double proInc = 987.654;
  std::string line = "";
  
  std::stringstream ss;
  ss << name << "," << soldMonth << "," << proInc;
  ss >> line;
  RosEntry* entry = RosEntryFactory::createRosEntry(line);

  ASSERT_TRUE( entry != NULL );
}

TEST(Ros, RosFile)
{
  

}


// TEST(RosTest, ReadFile)
//{
//  readFile("");
//  EXPECT_TRUE(readFile(""));
// }


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
