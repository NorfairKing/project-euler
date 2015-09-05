LANG = lua

LUAC = luac

SRC_EXT = lua
BIN_EXT = out
EXE_EXT = bin

LIB_DIR_NAME = lib
LIB_DIR = $(EDEN_ROOT)/$(LIB_DIR_NAME)/$(LANG)

SOLUTIONS=$(wildcard *.$(SRC_EXT))
OBJECTS=$(SOLUTIONS:.$(SRC_EXT)=.$(BIN_EXT))
SOLVERS=$(SOLUTIONS:.$(SRC_EXT)=.$(EXE_EXT))

all: $(SOLVERS)

%.$(EXE_EXT): %.$(BIN_EXT)
	rm -f $@
	touch $@
	echo export LUA_PATH=\"$(LIB_DIR)/?.$(SRC_EXT)\" >> $@
	echo lua $(shell realpath $<) >> $@
	chmod 775 $@

.SECONDARY: $(OBJECTS)
%.$(BIN_EXT): %.$(SRC_EXT)
	$(LUAC) -o $@ $<

test:
	@echo placeholder

DIRTY_EXT = *.$(BIN_EXT) *.$(EXE_EXT)
DIRTY = $(DIRTY_EXT)

clean:
	rm -f $(DIRTY)

love:
	@echo not war
