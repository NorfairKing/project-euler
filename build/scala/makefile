LANG = scala

SC = scalac

SRC_EXT = $(LANG)
BIN_EXT = bin
LIB_EXT = jar
CLASS_EXT = class

LIB_DIR_NAME = lib
LIB_DIR  = $(EDEN_ROOT)/$(LIB_DIR_NAME)/$(LANG)

SOLUTION_BIN_NAME = solution
SOLUTION_BIN = $(SOLUTION_BIN_NAME).$(BIN_EXT)

SOLUTION_NAME = Solution
SOLUTION_CLASS = $(SOLUTION_NAME).$(CLASS_EXT)
SOLUTION_SRC = $(SOLUTION_NAME).$(SRC_EXT)
SOLUTION_LIB = $(SOLUTION_NAME).$(LIB_EXT)

LIB_NAME = eulerlib
LIB_FILE = $(LIB_NAME).$(LIB_EXT)
LIB_CLASSES = $(wildcard LIB_DIR/*/*.class)
LIBRARY = $(LIB_DIR)/$(LIB_FILE)

MANIFEST = MANIFEST.MF

PWD = $(shell pwd)

STUB_NAME = stub
STUB_FILE = $(STUB_NAME).sh
define STUB
#!/bin/sh
scala -classpath "$(LIB_DIR):$(PWD)" $(SOLUTION_NAME)
endef
export STUB


all: $(SOLUTION_BIN)

$(SOLUTION_BIN): $(STUB_FILE) $(SOLUTION_CLASS)
	cat $(STUB_FILE) > $(SOLUTION_BIN)
	chmod 775 $(SOLUTION_BIN)

$(SOLUTION_CLASS): $(SOLUTION_SRC)
	scalac $(SOLUTION_SRC) -classpath $(LIBRARY)

$(STUB_FILE):
	echo "$$STUB" > $(STUB_FILE)


DIRTY_EXT = *.$(LIB_EXT) *.$(BIN_EXT) *.$(CLASS_EXT)
DIRTY = $(DIRTY_EXT) $(MANIFEST) $(STUB_FILE)

clean:
	rm -f $(DIRTY)

test:
	@echo placeholder

love:
	@echo not war
