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
  public:
    typedef std::vector<RosEntry*> RosEntryVector;
    
    RosFile(std::string fileName)
      : mFileName(fileName)
    {
    }

    double
    getProjectedIncome() const
    { return mReadTotalIncome;  }

    double
    getCalcTotalIncome() const 
    {
      double result = .0;
      RosEntryVector::const_iterator it = mEntries.begin();
      while ( it != mEntries.end() )
      {
        result += (*it)->getProjectedIncome();
        ++it;
      }

      return result;
    }

    double
    getDiscrepancy() const
    {
      return getProjectedIncome() - getCalcTotalIncome();
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

    RosEntryVector
    getRosEntries() const
    {
      return mEntries;
    }

  private:
    std::string mFileName;
    RosEntryVector mEntries;
    double mReadTotalIncome;

  };

}

#endif // ROSFILE_H_
