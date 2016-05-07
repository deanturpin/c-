.SILENT:

all: foo

# List of all directories containing a makefile
source_dirs := $(dir $(wildcard */makefile))

# cppcheck from top level
cppcheck:
	cppcheck --enable=all . 1> /dev/null

# Include What You Use
iwyu:
	$(foreach dir, $(source_dirs), make -j -C $(dir) iwyu;)

# Build each project
foo:
	$(foreach dir, $(source_dirs), make -j -C $(dir);)

# Clean each project
clean:
	$(foreach dir, $(source_dirs), make -j -C $(dir) clean;)

# Call run script if present
run: foo
	$(foreach dir, $(source_dirs), make -C $(dir) run;)
