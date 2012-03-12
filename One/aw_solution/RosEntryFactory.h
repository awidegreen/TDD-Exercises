#ifndef ROSENTRYFACORTY_H_
#define ROSENTRYFACORTY_H_

#include "RosEntry.h"

// std lib
#include <string>

namespace ros
{

  class RosEntryFactory
  {
  private:
    // prefend external instaniation 
    RosEntryFactory();

  public:
    static RosEntry
    createRosEntry(const std::string& line);
  };
  
}


#endif // ROSENTRYFACORTY_H_
