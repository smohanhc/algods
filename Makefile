# Makefile
# License : GPL 
# Copyright : Sumod K Mohan
# Nov 12, 2013

CPP = g++
OPT = --std=c++0x
DBG = -g -Wall
CFLAGS = $(DBG) $(OPT) 
LDFLAGS = -lm 
TESTDIR = ./test
INCLUDEDIR = ./include
IFLAGS = -I$(INCLUDEDIR) -I.


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

%: $(TESTDIR)/%_test.cpp
	$(CPP) $(CFLAGS) -o $@ $@.cpp $< $(IFLAGS) $(LDFLAGS)

clean:
	-rm -f *.o
#	-rm -f $(PROGRAMS)
#	-rm -f $(OBJECTS)

#tags : 
#	ctags $(SRCS)
