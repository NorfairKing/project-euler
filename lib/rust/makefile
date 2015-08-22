RUSTC = rustc

SRCS = $(wildcard *.rs)
LIB_NAME = euler
LIB_FILE = lib$(LIB_NAME).rlib

all:
	$(RUSTC) --crate-type=lib -o $(LIB_FILE) $(SRCS)

love:
	@echo not war
