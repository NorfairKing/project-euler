CC = gcc

BIN_NAME = solution.bin
SOLUTION_NAME = solution.c

OUTPUT_FLAG = -o $(BIN_NAME)
OPTIMISATION_FLAG = -O3

WARNING_FLAGS = -Wall -Werror

LIB_DIR = $(EDEN_ROOT)/lib/c
LIB_DIR_FLAGS = -L$(LIB_DIR) -I$(LIB_DIR)

LIBS = -leuler

CC_FLAGS = $(OPTIMISATION_FLAG) \
           $(WARNING_FLAGS) \
           $(LIB_DIR_FLAGS) \
           $(LIBS) \
           $(OUTPUT_FLAG) \

all: solver

solver:
	$(CC) $(SOLUTION_NAME) $(CC_FLAGS) 


DIRTY_EXT = *.o
DIRTY = $(DIRTY_EXT) $(BIN_NAME)

clean:
	rm -f $(DIRTY)


love:
	@echo not war
