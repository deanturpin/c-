CC=clang++
RM=rm -f
STANDARD=c++1y
FLAGS=-Weverything -Wno-c++98-compat -std=$(STANDARD)

%.o:%.cpp
	echo comp $<
	$(CC) $(FLAGS) -o $@ -c $<

# Compile and link all source files into a single executable
objects := $(patsubst %.cpp, %.o, $(wildcard *.cpp))
foo: $(objects)
	$(CC) -o $@ $(objects) $(LFLAGS)

clean:
	echo tidy $(objects)
	$(RM) foo $(objects)

iwyu:
	$(foreach cpp, $(wildcard *.cpp), echo iwyu $(cpp) && iwyu -std=$(STANDARD) $(cpp) |& grep -- '- #include' || true;)

fresh: clean foo

cppcheck:
	cppcheck --enable=all . 1> /dev/null
