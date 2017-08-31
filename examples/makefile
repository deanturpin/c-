all: $(patsubst %.cpp, %.o, $(wildcard *.cpp))

# Compile and run
%.o: %.cpp
	clang++ -Wall -Wextra -pedantic -pedantic-errors -std=c++14 -o $@ $<
	# ./$@

wait:
	while :; do inotifywait -qe modify *.cpp; make; done

clean:
	rm -f *.o
