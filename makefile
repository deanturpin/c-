objects = $(patsubst %.cpp, tmp/%.o, $(wildcard *.cpp))

all:
	$(MAKE) -j $(shell nproc) $(objects)

CXX = clang++-7

FLAGS = --std=c++2a --all-warnings --extra-warnings --pedantic-errors \
	-Werror -Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor \
	-g -pg

tmp/%.o: %.cpp tmp
	$(CXX) $(FLAGS) -o $@ $< -lstdc++fs -lpthread && echo $<

tmp:
	mkdir $@

clean:
	rm -rf tmp
