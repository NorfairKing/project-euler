CC = gcc

OPTIMISATION_FLAG = -O3
WARNING_FLAGS = -Wall -Werror
CC_FLAGS = $(OUTPUT_FLAG) \
           $(OPTIMISATION_FLAG) \
           $(WARNING_FLAGS)

LIBS = euler.a

all: libs

libs: $(LIBS)

SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

euler.a: $(OBJS)
	ar rcs libeuler.a $(OBJS)

%.o : %.c
	$(CC) -c -fpic $(CC_FLAGS) $< -o $@

%.a: %.o
	ar rcs lib$@ $<



DIRTY_EXT = *.o *.so *.a
DIRTY = $(DIRTY_EXT) $(BIN_NAME)

clean:
	rm -f $(DIRTY)


love:
	@echo not war
