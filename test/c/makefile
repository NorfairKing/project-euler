CC = g++

TESTSUITE = testsuite.bin
LIB_FLAGS = -lgtest
OUTPUT_FLAG = -o $(TESTSUITE)
TEST_SRCS = *.cpp
SRC_DIR = ../../lib/c


FLAGS = $(LIB_FLAGS) \
		$(OUTPUT_FLAG)

test: compile
	./$(TESTSUITE)

compile:
	$(CC) $(TEST_SRCS) $(SRC_DIR)/*.[hc] -I$(SRC_DIR) $(FLAGS)

