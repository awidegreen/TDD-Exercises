
// std lib
#include <sstream>
#include <iostream>

#include "RosEntryFactory.h"
#include "RosEntry.h"

#include "strtk/strtk.hpp"

namespace ros
{

  RosEntryFactory::RosEntryFactory()
  {}

  /* static */
  RosEntry*
  RosEntryFactory::createRosEntry(const std::string& line)
  {
    std::string name;
    int soldMonth;
    double proInc;

    bool res = strtk::parse(line, ",", name, soldMonth, proInc);
    if ( res )
      return new RosEntry(name, soldMonth, proInc);
    else
      return NULL;
  }

}
