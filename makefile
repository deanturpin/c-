
objects = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
all: $(objects)
CXX = clang++-6.0

FLAGS = --std=c++17 --all-warnings --extra-warnings --pedantic-errors \
	-Werror -Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor \
	-g -pg

%.o: %.cpp
	$(CXX) $(FLAGS) -o $@ $< -lstdc++fs -lpthread && echo $< && ./$@

clean:
	rm -f *.o
