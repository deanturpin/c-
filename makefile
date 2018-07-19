objects = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
all:
	make --jobs $(shell nproc) $(objects)

CXX ?= g++

FLAGS = -g --coverage -Wall -Wextra -pedantic -pedantic-errors -std=c++17
%.o: %.cpp
	$(CXX) $(FLAGS) -o $@ $< && ./$@

clean:
	rm -f *.o
