CC = g++

OPTIMISATION_FLAG = -O3
WARNING_FLAGS = -Wall -Werror

LIB_DIR = $(EDEN_ROOT)/lib/c++
LIB_DIR_FLAGS = -L$(LIB_DIR) -I$(LIB_DIR)
STD_LIBS = -lm

CC_FLAGS = $(OPTIMISATION_FLAG) \
           $(WARNING_FLAGS) \
           $(LIB_DIR_FLAGS) \
		   $(STD_LIBS)

SRCS=$(wildcard $(LIB_DIR)/*.cpp)

# Make does not offer a recursive wildcard function, so here's one:
rwildcard = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))
# How to recursively find all files that match a pattern
ALL_SRCS = $(filter-out lib/src/main.o,$(call rwildcard,lib/,*.o))

SOLUTIONS = $(wildcard [a-z]*.cpp)
SOLVERS = $(SOLUTIONS:.cpp=.bin)

.PHONY: lib
all: lib $(SOLVERS)

%.bin : %.cpp
	$(CC) $< $(SRCS) $(ALL_SRCS) -o $@ $(CC_FLAGS)

ifeq ("$(wildcard lib)","") 
lib:
	@echo placholder
else
lib:
	$(MAKE) -C lib
endif

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
