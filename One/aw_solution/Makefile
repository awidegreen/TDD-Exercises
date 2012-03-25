# directorys
OBJS_DIR      = ./obj
SRC_DIR       = ./src
TEST_DIR      = ./test
# compiler
CXXFLAGS     += -g -Wall -Wno-long-long -I$(SRC_DIR)  #-Wextra
# src and objs
OBJECTS       = RosEntryFactory.o RosFileReader.o
SRC_EXT       = cpp
#test
GTEST_DIR     = ../../gtest
TEST_CXXFLAGS = $(CXXFLAGS) -I$(GTEST_DIR)/include -L$(GTEST_DIR)
# vpath
VPATH         = $(SRC_DIR) $(TEST_DIR)
# strtk options
STRTK_OPTIONS = -ansi -pedantic-errors -Wall -Wextra -Dstrtk_no_tr1_or_boost -lstdc++

all: ros

ros: $(addprefix $(OBJS_DIR)/,$(OBJECTS)) $(OBJS_DIR)/ros.o
	$(CXX) $(CXXFLAGS) -o ros $^

$(OBJS_DIR)/%.o:%.$(SRC_EXT)
	test -d $(OBJS_DIR) || mkdir $(OBJS_DIR)
	$(CXX) -c $(CXXFLAGS) $(STRTK_OPTIONS) $< -o $@

test: $(addprefix $(OBJS_DIR)/,$(OBJECTS)) $(OBJS_DIR)/rostest.o
	$(CXX) $(TEST_CXXFLAGS) -lpthread -lgtest -o rostest $^ $(GTEST_DIR)/libgtest.a

$(OBJS_DIR)/rostest.o: rostest.$(SRC_EXT)
	$(CXX) -c $(TEST_CXXFLAGS) $< -o $@


.PHONY: clean cleanest

clean:
	$(RM) -fr $(OBJS_DIR)

cleanest: clean
	$(RM) ros rostest

