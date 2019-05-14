objects = $(patsubst %.cpp, tmp/%.o, $(wildcard *.cpp))

all: tmp
	$(MAKE) -k -j $(shell nproc) $(objects)

CXX = g++-9

FLAGS = --std=c++2a --all-warnings --extra-warnings -Wno-address \
	-Werror -Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor -O1

tmp/%.o: %.cpp
	$(CXX) $(FLAGS) -o $@ $< -lstdc++fs -lpthread
	./$@

tmp:
	mkdir -p $@

clean:
	rm -rf tmp *.bin *.out
