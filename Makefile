# Makefile
# License : GPL 
# Copyright : Sumod K Mohan
# Nov 12, 2013


# GTEST FLAGS.
GTEST_DIR = ~/sys/sw/gtest/gtest-1.7.0
GCPPFLAGS = -isystem $(GTEST_DIR)/include
GCXXFLAGS = -pthread -Wextra -Wall
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
		$(GTEST_DIR)/include/gtest/internal/*.h

# FLAGS
CPP = g++
OPT = --std=c++0x
DBG = -g -Wall
CPPFLAGS += $(DBG) $(OPT) $(GCPPFLAGS)
CXXFLAGS += $(GCXXFLAGS)
LDFLAGS = -lm 
TESTDIR = ./test
INCLUDEDIR = ./include
IFLAGS = -I$(INCLUDEDIR) -I. -I$(GTEST_HEADERS)

# Usually you shouldn't tweak such internal variables, indicated by a
# # trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# GTEST Targets
gtest-all.o : $(GTEST_SRCS_)
	        $(CXX) $(GCPPFLAGS) -I$(GTEST_DIR) $(GCXXFLAGS) -c \
		$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
		$(CXX) $(GCPPFLAGS) -I$(GTEST_DIR) $(GCXXFLAGS) -c \
		$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
		$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
		$(AR) $(ARFLAGS) $@ $^

# My definitions
PROGRAMS: rmq binaryheap disjoint_set

# Disable default rules
.SUFFIXES:

## Need to be fixed.
## SRCS = works, the variable is set, but is set to all values.i
## Somehow the build rule doesn't work.
#SRCS = $(PROGRAMS:=.cpp)
#TEST_SRCS = $(PROGRAMS:=_test.cpp)
#HEADERS = $(PROGRAMS:=.h)
#%: $(TESTDIR)/$(TEST_SRCS) $(INCLUDEDIR)/$(HEADERS) $(SRCS)
#	$(CPP) $(CFLAGS) -o $@ $(SRCS) $(TESTDIR)/$(TEST_SRCS) $(IFLAGS) $(LDFLAGS)


all: $(PROGRAMS)

%: $(TESTDIR)/%_gtest.cpp $(INCLUDEDIR)/%.h $(GTEST_HEADERS)
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) -o $@ $@.cpp $< $(IFLAGS) $(LDFLAGS)

clean:
	-rm -f *.o
#	-rm -f $(PROGRAMS)
#	-rm -f $(OBJECTS)

#tags : 
#	ctags $(SRCS)
