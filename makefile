# Build objects for each cpp
all: $(patsubst %.cpp, %.o, $(wildcard *.cpp))

%.o: %.cpp
	clang++ -Wall -Wextra -pedantic -pedantic-errors -std=c++1y -lpthread -o $@ $<

wait:
	while :; do inotifywait -qe modify *.cpp; make -j; done

clean:
	rm -f *.o

clang-format:
	$(foreach file, $(wildcard *.cpp), clang-format $(file) > blah; mv blah $(file) || true;)
