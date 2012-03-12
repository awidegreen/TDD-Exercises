#ifndef ROSFILEREADER_H_
#define ROSFILEREADER_H_

#include "RosFile.h"

// std lib
#include <string>

namespace ros
{
  class RosFileReader
  {
  private:
    // avoid instaniation
    RosFileReader();
  public:
    static RosFile*
      parseRosFile(const std::string& rosFile);
  };
} // namespace

#endif // ROSFILEREADER_H_
