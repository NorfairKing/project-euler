NAME = solution.bin
SRC = solution.hs
BIN = $(NAME)

GHC = ghc
GHC_OPTIMISATION = -O2
LIB_DIR = $(EDEN_ROOT)/lib/haskell
GHC_FLAGS = 	-fwarn-unused-imports \
				-fforce-recomp \
				-fwarn-incomplete-patterns \
				-Wall \
				-fno-warn-unused-do-bind \
				-fno-warn-name-shadowing
SRC_DIR_FLAGS = -i$(LIB_DIR)
GHC_OPTIONS = 	-threaded \
				$(GHC_OPTIMISATION) \
				$(GHC_FLAGS) \
				$(SRC_DIR_FLAGS)
SOLUTIONS=$(wildcard [a-z]*.hs)
SOLVERS=$(SOLUTIONS:.hs=.bin)


all: $(SOLVERS)

%.bin: %.hs
	$(GHC) $(GHC_OPTIONS) -o $@ --make $< 

TESTSUITE = testsuite.bin
TEST_SRC = Test.hs
TEST_BOILERPLATE = $(EDEN_ROOT)/build/haskell/test-boilerplate.hs
TMP_SRC = TestTmp.hs

test: $(TESTSUITE)
	./$(TESTSUITE)

$(TESTSUITE): $(TEST_SRC)
	cat $(TEST_BOILERPLATE) $(TEST_SRC) > $(TMP_SRC)
	$(GHC) -o $(TESTSUITE) $(TMP_SRC) --make -main-is TestTmp.test
	
	
DIRTY_EXT = *.o *.hi *.bin

clean:
	rm -f $(BIN) $(DIRTY_EXT)

love:
	@echo "not war"
