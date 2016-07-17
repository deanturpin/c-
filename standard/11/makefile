clean:
	rm -f *.o

# Compile and run
%.o: %.cpp
	clang++ -Wall -Wextra -pedantic -pedantic-errors -std=c++11 -o $@ $<
	./$@
