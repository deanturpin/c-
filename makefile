objects = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

all:
	$(MAKE) -j $(shell nproc) $(objects)

CXX = clang++-7

FLAGS = --std=c++2a --all-warnings --extra-warnings --pedantic-errors \
	-Werror -Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor \
	-g -pg

%.o: %.cpp
	$(CXX) $(FLAGS) -o $@ $< -lstdc++fs -lpthread && echo $< && ./$@

clean:
	rm -f *.o
