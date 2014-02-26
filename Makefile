# Makefile
# License : GPL 
# Copyright : Sumod K Mohan
# Nov 12, 2013


# GTEST FLAGS.
GTEST_DIR = /home/sumod/sys/sw/gtest/gtest-1.7.0
GCPPFLAGS = -isystem $(GTEST_DIR)/include
GCXXFLAGS = -pthread -Wextra -Wall
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
		$(GTEST_DIR)/include/gtest/internal/*.h
GIFLAGS = -I$(GTEST_HEADERS)
GLFLAGS = -lpthread

# FLAGS
CPP = g++
OPT = --std=c++0x

RELEASE = -c -03
DEBUG = -c -g -D_DEBUG -Wall -Wextra

CPPFLAGS += $(DEBUG) $(OPT) 
CXXFLAGS += 
LDFLAGS = -lm 
IFLAGS = -I$(INCDIR) -I. 

TESTDIR = ./test
INCDIR = ./include
BLDIR = ./build


#########################################################################
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
#########################################################################

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
#%: $(TESTDIR)/$(TEST_SRCS) $(INCDIR)/$(HEADERS) $(SRCS)
#	$(CPP) $(CFLAGS) -o $@ $(SRCS) $(TESTDIR)/$(TEST_SRCS) $(IFLAGS) $(LDFLAGS)


all: $(PROGRAMS)

#Update prog: 
#prog: 
#debug: CFLAGS=$(DEBUG)
#debug: prog

$(BLDIR)/%.o: %.cpp $(INCDIR)/%.h
	$(CPP) $(CPPFLAGS) $(CXXFLAGS) -c $< $(IFLAGS) -o $@

$(BLDIR)/%_gtest.o: $(TESTDIR)/%_gtest.cpp $(INCDIR)/%.h $(GTEST_HEADERS)
	$(CPP) $(GCPPFLAGS) $(GCXXFLAGS) -c $< $(IFLAGS) -o $@

%: $(BLDIR)/%_gtest.o $(BLDIR)/%.o $(INCDIR)/%.h $(GTEST_HEADERS) gtest_main.a
	$(CPP) $(OPT) -o $@ $< $(BLDIR)/$*.o gtest_main.a $(IFLAGS) $(LDFLAGS) $(GLFLAGS)

clean:
	-rm -f *.o

tags : 
	ctags $(SRCS)
