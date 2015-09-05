SC = scalac

SRC_EXT = scala
CLASS_EXT = class
LIB_EXT = jar

LIB_NAME = eulerlib
LIBRARY = $(LIB_NAME).$(LIB_EXT)

SOURCES = $(wildcard projecteuler/*.$(SRC_EXT))
CLASSES = $(SOURCES:.$(SRC_EXT)=.$(CLASS_EXT))

all: $(CLASSES)
	jar -cvf $(LIBRARY) $(CLASSES)

$(CLASSES): $(SOURCES)
	$(SC) $(SOURCES)

DIRTY_EXT = */*.$(CLASS_EXT) *.$(LIB_EXT)
DIRTY = $(DIRTY_EXT)

clean:
	rm -f $(DIRTY)

love:
	@echo not war
