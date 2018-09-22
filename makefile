objects = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
all: $(objects)

CXX ?= g++-8

FLAGS = --std=c++17 --all-warnings --extra-warnings --pedantic-errors \
	-Werror -Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor

%.o: %.cpp
	$(CXX) $(FLAGS) -o $@ $< -lstdc++fs -lpthread && ./$@

clean:
	rm -f *.o
