#ifndef ROSENTRY_H_
#define ROSENTRY_H_

/**
 * Copyright 2012 Armin Widegeen.
 * All rights reserved.
 */ 

#include <string>

namespace ros
{
  class RosEntry
  {
  private:
    std::string mName;
    int mSoldMonth;
    double mProjectedIncome;
  public:
    RosEntry(std::string name, int soldMonth, double projectedIncome)
      : mName(name),
        mSoldMonth(soldMonth),
        mProjectedIncome(projectedIncome)
    {}

    const std::string&
    getName() const
    { return mName; }

    const int
    getSoldMonth() const
    { return mSoldMonth; }

    const double
    getProjectedIncome() const
    { return mProjectedIncome; } 
    
  };

}

#endif // ROSENTRY_H_
