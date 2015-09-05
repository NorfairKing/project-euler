LANG = java

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

STUB_NAME = stub
STUB_FILE = $(STUB_NAME).sh
define STUB
#!/bin/sh
MYSELF=`which "$$0" 2>/dev/null`
[ $$? -gt 0 -a -f "$$0" ] && MYSELF="./$$0"
java=java
if test -n "$$JAVA_HOME"; then
    java="$$JAVA_HOME/bin/java"
fi
exec "$$java" -classpath $(LIB_DIR) $$java_args -jar $$MYSELF "$$@"
exit 1 
endef
export STUB


all: $(SOLUTION_BIN)

$(SOLUTION_BIN): $(STUB_FILE) $(SOLUTION_LIB)
	cat $(STUB_FILE) $(SOLUTION_LIB) > $(SOLUTION_BIN)
	chmod 775 $(SOLUTION_BIN)

$(SOLUTION_LIB): $(LIBRARY) $(MANIFEST) $(SOLUTION_CLASS)
	jar -cvmf $(MANIFEST) $(SOLUTION_LIB) $(SOLUTION_CLASS) $(LIBRARY)

$(MANIFEST): $(LIBRARY) $(SOLUTION_CLASS)
	rm -f $(MANIFEST)
	touch $(MANIFEST)
	echo Main-Class: $(SOLUTION_NAME) >> $(MANIFEST)
	echo Class-Path: $(LIBRARY) >> $(MANIFEST)

$(SOLUTION_CLASS): $(SOLUTION_SRC)
	javac $(SOLUTION_SRC) -classpath $(LIB_DIR)

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
