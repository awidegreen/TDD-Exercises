#ifndef ROSFILE_H_
#define ROSFILE_H_

// std::lib
#include "RosEntry.h"

#include <string>
#include <vector>

namespace ros
{
  class RosFile
  {
  private:
    typedef std::vector<RosEntry*> RosVector;
    
    std::string mFileName;
    RosVector mEntries;
    double mReadTotalIncome;

  public:
    RosFile(std::string fileName)
      : mFileName(fileName)
    {
    }

    double
    getReadTotalIncome() const
    { return mReadTotalIncome;  }

    double
    getCalcTotalIncome() const 
    {
      double result = .0;
      RosVector::const_iterator it = mEntries.begin();
      while ( it != mEntries.end() )
      {
        result += (*it)->getProjectedIncome();
        ++it;
      }

      return result;
    }

    void
    addRosEntry(RosEntry* entry)
    {
      mEntries.push_back(entry);
    }

    void
    setReadTotalIncome(const double income)
    {
      mReadTotalIncome = income;
    }
  };

}

#endif // ROSFILE_H_
