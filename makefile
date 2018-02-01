# Build objects for each cpp
all: $(patsubst %.cpp, %.o, $(wildcard *.cpp))

%.o: %.cpp
	g++-6 -g -Wall -Wextra -pedantic -pedantic-errors -std=c++17 -lpthread -o $@ $<

wait:
	while :; do inotifywait -qe modify *.cpp; make -j; done

clean:
	rm -f *.o

format:
	$(foreach file, $(wildcard *.cpp), clang-format -i $(file) || true;)
