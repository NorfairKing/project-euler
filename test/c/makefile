CPP = g++

TESTSUITE = testsuite.bin
LIB_FLAGS = -lgtest
OUTPUT_FLAG = -o $(TESTSUITE)
TEST_SRCS = *.cpp
SRC_DIR = $(EDEN_ROOT)/lib/c


FLAGS = $(LIB_FLAGS) \
		$(OUTPUT_FLAG)

test: compile
	./$(TESTSUITE)

SRCS = SRCS=$(wildcard $(LIB_DIR)/*.[hc])

compile:
	$(CPP) $(TEST_SRCS) $(SRC_DIR)/*.[hc] -I$(SRC_DIR) $(FLAGS)

