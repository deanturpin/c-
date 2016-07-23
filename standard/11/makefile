CC=clang++

clean:
	rm -f *.o

# Compile and run
%.o: %.cpp
	${CC} -Wall -Wextra -pedantic -pedantic-errors -std=c++11 -o $@ $<
	./$@
