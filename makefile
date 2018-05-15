objects=$(patsubst %.cpp, %.o, $(wildcard *.cpp))

# Build objects for each cpp
all: $(objects)

CXX=g++-6
%.o: %.cpp
	$(CXX) -g --coverage -Wall -Wextra -pedantic -pedantic-errors -std=c++14 -lpthread -o $@ $<
	./$@

wait:
	while :; do inotifywait -qe modify *.cpp; make; done

clean:
	rm -f *.o

tidy:
	$(foreach file, $(wildcard *.cpp), clang-format -i $(file) || true;)

format:
	clang-format -i *.cpp
