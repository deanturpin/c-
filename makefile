objects = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
all: $(objects)

CXX ?= g++

FLAGS = -g --coverage -Wall -Wextra -pedantic -pedantic-errors -std=c++14
%.o: %.cpp
	$(CXX) $(FLAGS) -o $@ $<
	./$@

clean:
	rm -f *.o

format:
	clang-format -i *.cpp
