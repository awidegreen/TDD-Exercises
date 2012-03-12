// ros includes
#include "RosEntry.h"
#include "RosEntryFactory.h"
#include "RosFileReader.h"

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

  entry = RosEntryFactory::createRosEntry("");
  ASSERT_TRUE( entry == NULL );

  entry = RosEntryFactory::createRosEntry("asdasdasdasd,asdd,0222");
  ASSERT_TRUE( entry == NULL );

  entry = RosEntryFactory::createRosEntry("asddasd,2334,asdsd");
  ASSERT_TRUE( entry == NULL );

  entry = RosEntryFactory::createRosEntry("asddasd,2334,");
  ASSERT_TRUE( entry == NULL );

  entry = RosEntryFactory::createRosEntry("asddasd,23asdsd");
  ASSERT_TRUE( entry == NULL );

  entry = RosEntryFactory::createRosEntry("asddasd,,asdsd");
  ASSERT_TRUE( entry == NULL );
}

TEST(Ros, RosFile)
{
  std::string fileName = "../ROS_files/february-north_branch-2011.ros";
  
  RosFile* rosFile =
    RosFileReader::parseRosFile(fileName);

  ASSERT_TRUE( rosFile != NULL );
  ASSERT_TRUE( rosFile->getProjectedIncome() == 4284 );
  ASSERT_TRUE( rosFile->getCalcTotalIncome() == 4284 );
  ASSERT_TRUE( rosFile->getDiscrepancy() == 0 );
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
