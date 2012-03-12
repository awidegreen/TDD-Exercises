#include "RosFileReader.h"

#include "RosFile.h"
#include "RosEntry.h"
#include "RosEntryFactory.h"

// std lib
#include <fstream>
#include <sstream>
#include <iostream>

namespace ros
{
  RosFileReader::RosFileReader()
  {}
  
  /* static */
  RosFile*
  RosFileReader::parseRosFile(const std::string& rosFileName)
  {
    using namespace std;
    // file open and read, if file can not be open or
    // read correctly, return null.

    //std::cout << "rosFileName: " << rosFileName << std::endl;
    
    
    ifstream rosFile( rosFileName.c_str() );
    if ( rosFile.is_open() )
    {
      string line;
      string prevLine;
      RosFile* ros = new RosFile(rosFileName);
      
      while ( rosFile.good() )
      {
        getline(rosFile, line);

        //std::cout << "line: " << line << std::endl;
        
        RosEntry* entry = RosEntryFactory::createRosEntry(line);
        if ( entry != NULL)
          ros->addRosEntry(entry);

        if ( !line.empty() )
          prevLine = line;
      }
      rosFile.close();

      stringstream ss;
      double totalIncome = 0.0;
      ss << prevLine;
      ss >> totalIncome;
      ros->setReadTotalIncome(totalIncome);

      return ros;
    }
    
    return NULL;
  }

} // end namespace 
