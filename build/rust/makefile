RUSTC = rustc

OPTIMISATION_FLAG = -O

BUILD_DIR = $(EDEN_ROOT)/build/rust
BUILD_MANIFEST = $(BUILD_DIR)/Cargo.toml
LIB_DIR = $(EDEN_ROOT)/lib/rust
LIB_DIR_FLAGS = -L -lstatic=euler

RS_FLAGS = $(OPTIMISATION_FLAG) \
           $(LIB_DIR_FLAGS)

SOLUTIONS=$(wildcard [a-z]*.rs)
SOLVERS=$(SOLUTIONS:.rs=.bin)

all: $(SOLVERS)

%.bin : %.rs
	$(RUSTC) $< $(RS_FLAGS) -o $@


DIRTY_EXT = *.bin
DIRTY = $(DIRTY_EXT) $(BIN_NAME)

clean:
	rm -f $(DIRTY)


love:
	@echo not war
