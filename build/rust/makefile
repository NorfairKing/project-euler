RUSTC = rustc

BIN_NAME = solution.bin
SOLUTION_NAME = solution.rs

OPTIMISATION_FLAG = -O


LIB_DIR = $(EDEN_ROOT)/lib/rust
LIB_DIR_FLAGS = -L$(LIB_DIR)

RS_FLAGS = $(OPTIMISATION_FLAG) \
           $(LIB_DIR_FLAGS)

SRCS=$(wildcard $(LIB_DIR)/*.rs)

SOLUTIONS=$(wildcard [a-z]*.rs)
SOLVERS=$(SOLUTIONS:.rs=.bin)

all: $(SOLVERS)

%.bin : %.rs
	$(RUSTC) $< $(SRCS) $(RS_FLAGS) -o $@

TEST_SRC = placeholder
TESTSUITE = testsuite.bin

ifeq ("$(wildcard $(TEST_SRC))","")
test:
	@echo "not testing because there is no test"
else
test: $(TESTSUITE)
	  ./$(TESTSUITE)

$(TESTSUITE): $(TEST_SRC)
	@echo placeholder
endif

DIRTY_EXT = *.bin
DIRTY = $(DIRTY_EXT) $(BIN_NAME)

clean:
	rm -f $(DIRTY)


love:
	@echo not war
