include ../../rules.mak

# Create main, build foo
all: main.cpp foo

PHONY: main.cpp
main.cpp:
	../create_main

run: foo
	./foo
