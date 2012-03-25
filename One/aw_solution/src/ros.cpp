#include "ros.h"

#include <iostream>

const bool
readFile(const std::string& s) 
{
  if (s.size() == 0)
    return false;
  return true;
}


int main()
{
  readFile(""); //"hallo", content);

  std::cout << "I'm in main" << std::endl;

  return 0;
}

