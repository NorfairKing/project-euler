CC = gcc

SRC_EXT = c
OBJ_EXT = o
ARC_EXT = a

OPTIMISATION_FLAG = -O3
WARNING_FLAGS = -Wall -Werror
CC_FLAGS = \
	$(OUTPUT_FLAG) \
  $(OPTIMISATION_FLAG) \
  $(WARNING_FLAGS)

LIBRARY_NAME = euler
LIBRARY = lib$(LIBRARY_NAME).$(ARC_EXT)

all: libs

libs: $(LIBS)

SRCS=$(wildcard *.$(SRC_EXT))
OBJS=$(SRCS:.$(SRC_EXT)=.$(OBJ_EXT))

%.$(OBJ_EXT) : %.$(SRC_EXT)
	$(CC) -c -fpic $(CC_FLAGS) $< -o $@

euler.a: $(OBJS)
	ar rcs $(LIBRARY) $(OBJS)

DIRTY_EXT = *.$(OBJ_EXT) *.$(ARC_EXT)
DIRTY = $(DIRTY_EXT) $(BIN_NAME)

clean:
	rm -f $(DIRTY)


love:
	@echo not war
