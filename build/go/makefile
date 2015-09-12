LANG = go

GC = go build

SRC_EXT = go
BIN_EXT = bin

SOLUTIONS = $(wildcard *.$(SRC_EXT))
SOLVERS = $(SOLUTIONS:.$(SRC_EXT)=.$(BIN_EXT))

all: $(SOLVERS)

%.$(BIN_EXT) : %.$(SRC_EXT)
	  $(GC) -o $@ $<

test:
	@echo placeholder
