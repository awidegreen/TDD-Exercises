# google test vars
GTEST_DIR = ../../gtest

SRCDIR=src
TESTDIR=test

# c++ compiler
#CXX=g++
# precompiler flags
CPPFLAGS += -I$(GTEST_DIR)/include -I$(SRCDIR)
# c++ compiler flags
CXXFLAGS += -I$(GTEST_DIR)/include -I$(SRCDIR) -L$(GTEST_DIR) -c -Wall -Wextra -Wno-ignored-qualifiers -g
# bind flags
LDFLAGS=

# sources
SOURCES = $(SRCDIR)/RosEntry.h $(SRCDIR)/RosEntryFactory.h $(SRCDIR)/RosEntryFactory.cpp $(SRCDIR)/RosFileReader.h $(SRCDIR)/RosFileReader.cpp
TESTSOURCES = $(TESTDIR)/ros_unittest.cpp
# obj files
OBJECTS = $(SOURCES:.cpp=.o)
TESTOBJECTS = $(TESTSOURCES:.cpp=.o)

# executable name
EXECUTABLE = ros
# tests
TESTS = ros_unittest



all: $(SOURCES) $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) $(SRCDIR)/*.o *.o $(TESTDIR)/*.o *~ $(EXECUTABLE) $(TESTS)


$(TESTS): $(OBJECTS) $(TESTOBJECTS) 
	$(CXX) $(LDFLAGS) $(OBJECTS) $(TESTOBJECTS) $(GTEST_DIR)/libgtest.a -lpthread -o $@