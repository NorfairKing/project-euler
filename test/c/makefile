CPP = g++

TESTSUITE = main.bin
SRC_DIR = $(EDEN_ROOT)/lib/c
LIB_SRCS = $(SRC_DIR)/*.[hc]

LIB_FLAGS = -lgtest
FLAGS = $(LIB_FLAGS)

TESTCASES=$(wildcard *.cpp)
UNITTESTS=$(TESTCASES:.cpp=.bin)

all: $(TESTSUITE) $(UNITTESTS)

test: $(TESTSUITE)
	./$(TESTSUITE)

main.bin:
	$(CPP) $(TESTCASES) $(LIB_SRCS) -I$(SRC_DIR) $(FLAGS) -o $(TESTSUITE)

%.bin: %.cpp
	$(CPP) main.cpp $< $(LIB_SRCS) -I$(SRC_DIR) $(FLAGS) -o $@

DIRTY = *.bin

clean:
	rm -f $(DIRTY)
