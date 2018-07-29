objects = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
all:
	make --jobs $(shell nproc) $(objects)

CXX ?= g++-8

FLAGS = -g --coverage \
	-std=c++17 --all-warnings --extra-warnings -pedantic-errors \
	-Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor

%.o: %.cpp
	$(CXX) $(FLAGS) -o $@ $< && ./$@

clean:
	rm -f *.o
