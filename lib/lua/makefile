LUAC = luac

SRC_EXT = lua
BIN_EXT = out

SRCS=$(wildcard *.$(SRC_EXT))
OBJECTS=$(SRCS:.$(SRC_EXT)=.$(BIN_EXT))

all: $(OBJECTS)

%.$(BIN_EXT): %.$(SRC_EXT)
	$(LUAC) -o $@ $<


love:
	@echo not war
