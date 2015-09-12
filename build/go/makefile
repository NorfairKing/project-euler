LANG = go

GC = go build

SRC_EXT = go
BIN_EXT = bin

LIB_DIR_NAME = lib
LIB_DIR = $(EDEN_ROOT)/$(LIB_DIR_NAME)/$(LANG)

SOLUTIONS = $(wildcard *.$(SRC_EXT))
SOLVERS = $(SOLUTIONS:.$(SRC_EXT)=.$(BIN_EXT))

all: $(SOLVERS)

%.$(BIN_EXT) : %.$(SRC_EXT)
	export GOPATH="$$GOPATH:$(LIB_DIR)" && $(GC) -o $@ $<

test:
	@echo placeholder
