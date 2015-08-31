JAVAC = javac

SRC_EXT = java
CLASS_EXT = class
LIB_EXT = jar

LIB_NAME = eulerlib
LIBRARY = $(LIB_NAME).$(LIB_EXT)

SOURCES = $(wildcard projecteuler/*.$(SRC_EXT))
CLASSES = $(SOURCES:.$(SRC_EXT)=.$(CLASS_EXT))

all: $(CLASSES)
	jar -cvf $(LIBRARY) $(CLASSES)

%.$(CLASS_EXT): %.$(SRC_EXT)
	$(JAVAC) $<


love:
	@echo not war
