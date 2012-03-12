#include "RosFileReader.h"

#include "RosFile.h"
#include "RosEntry.h"
#include "RosEntryFactory.h"

// std lib
#include <fstream>

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

    
    ifstream rosFile( rosFileName.c_str(), ifstream::in );
    if ( rosFile.is_open() )
    {
      string line;
      RosFile* ros = new RosFile(rosFileName);
      
      while ( rosFile.good() )
      {
        getline(rosFile, line);
        RosEntry* entry = RosEntryFactory::createRosEntry(line);
        if ( entry != NULL)
          ros->addRosEntry(entry);
      }
      rosFile.close();
    }
    
    return NULL;
  }

} // end namespace 
