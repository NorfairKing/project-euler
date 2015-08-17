CC = gcc

BIN_NAME = solution.bin
SOLUTION_NAME = solution.c

OPTIMISATION_FLAG = -O3

WARNING_FLAGS = -Wall -Werror

LIB_DIR = $(EDEN_ROOT)/lib/c
LIB_DIR_FLAGS = -L$(LIB_DIR) -I$(LIB_DIR)
STD_LIBS = -lm

CC_FLAGS = $(OPTIMISATION_FLAG) \
           $(WARNING_FLAGS) \
           $(LIB_DIR_FLAGS) \
		   $(STD_LIBS)

SRCS=$(wildcard $(LIB_DIR)/*.c)

SOLUTIONS=$(wildcard [a-z]*.c)
SOLVERS=$(SOLUTIONS:.c=.bin)

all: $(SOLVERS)

%.bin : %.c
	$(CC) $< $(SRCS) -o $@ $(CC_FLAGS)

## Tests

CPP = g++
TESTSUITE = testsuite.bin
LIB_FLAGS = -lgtest
TEST_SRC = test.cpp
TEST_BOILERPLATE = $(EDEN_ROOT)/build/c/test-boilerplate.c
TMP_SRC = TestTmp.cpp

FLAGS = \
	$(LIB_DIR_FLAGS) \
	$(LIB_FLAGS)

ifeq ("$(wildcard $(TEST_SRC))","")
test:
	@echo "not testing because there is no test"
else
test: $(TESTSUITE)
	./$(TESTSUITE)

$(TESTSUITE): $(TEST_SRC)
	cat $(TEST_BOILERPLATE) $(TEST_SRC) > $(TMP_SRC)
	$(CPP) $(SRCS) $(TMP_SRC) -o $(TESTSUITE) $(FLAGS)
endif

DIRTY_EXT = *.o *.bin
DIRTY = $(DIRTY_EXT) $(BIN_NAME)

clean:
	rm -f $(DIRTY)


love:
	@echo not war
