clean:
	rm -f *.o

# Compile and run
%.o: %.cpp
	clang++ -Weverything -Wno-c++98-compat -std=c++1z -o $@ $<
	./$@
