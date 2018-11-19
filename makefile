objects = $(patsubst %.cpp, tmp/%.o, $(wildcard *.cpp))

all: tmp build run

build:
	$(MAKE) -j $(shell nproc) $(objects)

run:
	echo run


CXX = clang++-7

FLAGS = --std=c++2a --all-warnings --extra-warnings --pedantic-errors \
	-Werror -Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor \
	-g -pg

tmp/%.o: %.cpp
	$(CXX) $(FLAGS) -o $@ $< -lstdc++fs -lpthread

tmp:
	mkdir $@

clean:
	rm -rf tmp
