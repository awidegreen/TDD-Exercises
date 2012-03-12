#ifndef ROSENTRYFACORTY_H_
#define ROSENTRYFACORTY_H_

// std lib
#include <string>

namespace ros
{
  
  // forward declaration
  class RosEntry;

  class RosEntryFactory
  {
  private:
    // prefend external instaniation 
    RosEntryFactory();

  public:
    /**
     * Returns NULL is line could not be parsed.
     */
    static RosEntry*
    createRosEntry(const std::string& line);
  };
  
}


#endif // ROSENTRYFACORTY_H_
