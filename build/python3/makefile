LANG = python3

SRC_EXT = py
BIN_EXT = bin

SOLUTIONS=$(wildcard *.$(SRC_EXT))
SOLVERS=$(SOLUTIONS:.$(SRC_EXT)=.$(BIN_EXT))
LIB_DIR_NAME = lib
LIB_DIR = $(EDEN_ROOT)/$(LIB_DIR_NAME)/$(LANG)


all: $(SOLVERS)

PYTHON3=$(shell which python3)

%.bin: %.py
	rm -f $@
	touch $@
	echo "export export PYTHONPATH='$(LIB_DIR)'" >> $@
	echo python3 $(shell realpath $<) >> $@
	chmod 775 $@

test:
	@echo placeholder

DIRTY_EXT = *.py[oc]
DIRTY = $(DIRTY_EXT)

clean:
	rm -f $(DIRTY)

love:
	@echo not war
