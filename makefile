objects = $(patsubst %.cpp, tmp/%.o, $(wildcard *.cpp))

all: tmp
	$(MAKE) -j $(shell nproc) $(objects)

CXX = g++-8

FLAGS = --std=c++2a --all-warnings --extra-warnings -Wno-address \
	-Werror -Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor \
	-g -pg -O1

tmp/%.o: %.cpp
	$(CXX) $(FLAGS) -o $@ $< -lstdc++fs -lpthread
	time ./$@

tmp:
	mkdir $@

clean:
	rm -rf tmp *.bin *.out
