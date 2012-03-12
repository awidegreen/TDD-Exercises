#include "RosEntryFactory.h"
#include "RosEntry.h"

// std lib
#include <sstream>
#include <iostream>


namespace ros
{

  RosEntryFactory::RosEntryFactory()
  {}

  /* static */
  RosEntry*
  RosEntryFactory::createRosEntry(const std::string& line)
  {
    const char DELIMITER = ',';
    const int NUM_OF_ELEMENTS = 3;
    std::string name;
    int soldMonth;
    double proInc;
    size_t startAt = 0;
    size_t endAt = 0;
   
    if ( line.empty() )
      return NULL;

    for ( short i = 0; i < NUM_OF_ELEMENTS; ++i )
    {
      endAt = line.find(DELIMITER, startAt);
      if ( i == NUM_OF_ELEMENTS-1 )
      {
        endAt = line.size();
      }
      else if ( endAt == std::string::npos )
      {
        return NULL;
      }

      std::string sub = line.substr(startAt, endAt - startAt); 
      //   std::cout << "startat:" << startAt << " - endAt:" << endAt << " - sub:" << sub << std::endl;

      switch ( i )        
      {
      case 0:
        name = sub;
        break;
      case 1:
        {
          std::stringstream ss;
          ss << sub;
          ss >> soldMonth;
          if ( sub != "0"  && soldMonth == 0)
            return NULL;
          break;
        }
      case 2:
        {
          std::stringstream ss;
          ss << sub;
          ss >> proInc;
          if ( (sub != "0.0" || sub != "0" )  && proInc == 0.0)
            return NULL;
          break;
        }
      default:
        // nop
        break;
      }
      
      startAt = endAt+1;
    }

//    std::cout << "name: " << name << " soldmonth: " << soldMonth << " proInc: " << proInc << std::endl;

    return new RosEntry(name, soldMonth, proInc);
  }

}
