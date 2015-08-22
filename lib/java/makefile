JAVAC = javac
SOURCES = $(wildcard projecteuler/*.java)
CLASSES = $(SOURCES:.java=.class)

all: $(CLASSES)
	jar -cvf eulerlib.jar $(CLASSES)

%.class: %.java
	$(JAVAC) $<

love:
	@echo not war
