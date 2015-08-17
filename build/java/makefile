BIN_NAME = solution.bin
SRC_NAME = Solution.java
NAME     = Solution
LIB_DIR  = $(EDEN_ROOT)/lib/java
LIB_NAME = eulerlib.jar
EULERLIB = $(LIB_DIR)/$(LIB_NAME)
LIB_CLASSES = $(wildcard LIB_DIR/*/*.class)
MANIFEST = MANIFEST.MF

all: $(BIN_NAME)

STUB_NAME = stub.sh
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

$(BIN_NAME): $(SRC_NAME)
	javac $(SRC_NAME) -classpath $(EULERLIB)
	echo Main-Class: $(NAME) > $(MANIFEST)
	echo Class-Path: $(EULERLIB) >> $(MANIFEST)
	jar -cvmf MANIFEST.MF $(NAME).jar $(NAME).class $(EULERLIB)
	echo "$$STUB" > $(STUB_NAME)
	cat $(STUB_NAME) $(NAME).jar > $(BIN_NAME)
	chmod 775 $(BIN_NAME)

DIRTY = *.jar *.bin *.class $(MANIFEST)

clean:
	rm -f $(DIRTY)

test:
	@echo placeholder

love:
	@echo not war
