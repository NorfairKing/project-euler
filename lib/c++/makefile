CC = g++

SRC_EXT = cc
OBJ_EXT = o
ARC_EXT = a

OPTIMISATION_FLAG = -O3
WARNING_FLAGS = -Wall -Werror
STANDARD_FLAGS = -std=c++14
CC_FLAGS = \
	$(OUTPUT_FLAG) \
  $(OPTIMISATION_FLAG) \
  $(WARNING_FLAGS) \
	$(STANDARD_FLAGS)

LIBRARY_NAME = euler
LIBRARY = lib$(LIBRARY_NAME).$(ARC_EXT)

all: libs

libs: $(LIBRARY)

SRCS=$(wildcard *.$(SRC_EXT))
OBJS=$(SRCS:.$(SRC_EXT)=.$(OBJ_EXT))

%.$(OBJ_EXT) : %.$(SRC_EXT)
	$(CC) -c -fpic $(CC_FLAGS) $< -o $@

$(LIBRARY): $(OBJS)
	ar rcs $(LIBRARY) $(OBJS)

DIRTY_EXT = *.$(OBJ_EXT) *.$(ARC_EXT)
DIRTY = $(DIRTY_EXT)

clean:
	rm -f $(DIRTY)

love:
	@echo not war
