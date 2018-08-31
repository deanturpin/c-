objects = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
all:
	make --jobs $(shell nproc) $(objects)

CXX ?= g++-8

FLAGS = -g --coverage \
	-std=c++17 --all-warnings --extra-warnings \
	-Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor

%.o: %.cpp
	$(CXX) $(FLAGS) -o $@ $< -lstdc++fs -lpthread && ./$@

clean:
	rm -f *.o
