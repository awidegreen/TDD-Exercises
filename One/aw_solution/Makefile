# google test vars


# c++ compiler
#CXX=g++
# precompiler flags
CPPFLAGS += -I$(GTEST_DIR)/include
# c++ compiler flags
CXXFLAGS += -c -Wall -Wextra -Wno-ignored-qualifiers -g
# bind flags
LDFLAGS=

# sources
SOURCES = ros.cpp ros.h RosEntry.h RosEntryFactory.h RosEntryFactory.cpp RosFileReader.h RosFileReader.cpp
TESTSOURCES = ros_unittest.cpp
# obj files
OBJECTS = $(SOURCES:.cpp=.o)
TESTOBJECTS = $(TESTSOURCES:.cpp=.o)

# executable name
EXECUTABLE = ros
# tests
TEST = ros_unittest

all: $(SOURCES) $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLE)

$(TEST): $(OBJECTS) $(TESTOBJECTS) 
	$(CXX) $(LDFLAGS) $(OBJECTS) $(TESTOBJECTS) -lpthread -lgtest -o $@