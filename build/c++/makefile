LANG = c++

CC = g++

SRC_EXT = cc
TEST_EXT = $(SRC_EXT)
OBJ_EXT = o
BIN_EXT = bin

OPTIMISATION_FLAG = -O3
WARNING_FLAGS = -Wall -Werror
BUILD_DIR_NAME = build
BUILD_DIR = $(EDEN_ROOT)/$(BUILD_DIR_NAME)/$(LANG)
LIB_DIR_NAME = lib
LIB_DIR = $(EDEN_ROOT)/$(LIB_DIR_NAME)/$(LANG)
LIB_DIR_FLAGS = -L$(LIB_DIR) -I$(LIB_DIR)
STD_LIBS = -lm

CC_FLAGS = \
	$(OPTIMISATION_FLAG) \
  $(WARNING_FLAGS) \
  $(LIB_DIR_FLAGS) \
	$(STD_LIBS)

SRCS=$(wildcard $(LIB_DIR)/*.$(SRC_EXT))

SPECIFIC_LIB = lib
SPECIFIC_LIB_SRC = $(SPECIFIC_LIB)/src
SPECIFIC_LIB_MAIN_NAME = main
SPECIFIC_LIB_MAIN = $(SPECIFIC_LIB_SRC)/$(SPECIFIC_LIB_MAIN_NAME)


# Make does not offer a recursive wildcard function, so here's one:
rwildcard = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))
# How to recursively find all files that match a pattern
ALL_SRCS = $(filter-out $(SPECIFIC_LIB_MAIN).$(OBJ_EXT),$(call rwildcard,lib/,*.$(OBJ_EXT)))

SOLUTIONS = $(wildcard [a-z]*.$(SRC_EXT))
SOLVERS = $(SOLUTIONS:.$(SRC_EXT)=.$(BIN_EXT))

.PHONY: $(SPECIFIC_LIB)
all: $(SPECIFIC_LIB) $(SOLVERS)

%.bin : %.$(SRC_EXT)
	$(CC) $< $(SRCS) $(ALL_SRCS) -o $@ $(CC_FLAGS)

ifeq ("$(wildcard $(SPECIFIC_LIB))","") 
$(SPECIFIC_LIB):
else
$(SPECIFIC_LIB):
	$(MAKE) -C $(SPECIFIC_LIB)
endif

## Tests

TESTSUITE = testsuite.$(BIN_EXT)

LIB_FLAGS = -lgtest

TEST_SRC_NAME = test
TEST_BOILERPLATE_NAME = test-boilerplate
TMP_SRC_NAME = TestTmp
TEST_SRC = $(TEST_SRC_NAME).$(SRC_EXT)
TEST_BOILERPLATE = $(BUILD_DIR)/$(TEST_BOILERPLATE_NAME).$(SRC_EXT)
TMP_SRC = $(TEST_SRC_NAME).$(SRC_EXT)

TEST_FLAGS = \
	$(LIB_DIR_FLAGS) \
	$(LIB_FLAGS)

ifeq ("$(wildcard $(TEST_SRC))","")
test:
else
test: $(TESTSUITE)
	./$(TESTSUITE)

$(TESTSUITE): $(SRCS) $(TEST_TMP)
	$(CC) $(SRCS) $(TMP_SRC) -o $(TESTSUITE) $(TEST_FLAGS)

$(TMP_SRC): $(TEST_BOILERPLATE) $(TEST_SRC)
	cat $(TEST_BOILERPLATE) $(TEST_SRC) > $(TMP_SRC)
endif

DIRTY_EXT = *.$(OBJ_EXT) *.$(BIN_EXT)
DIRTY = $(DIRTY_EXT) $(BIN_NAME) $(TMP_SRC)

clean:
	rm -f $(DIRTY)


love:
	@echo not war
