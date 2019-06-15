objects = $(patsubst %.cpp, tmp/%.o, $(wildcard *.cpp))

all: tmp
	$(MAKE) -k -j $(shell nproc) $(objects)

CXX = g++-9

FLAGS = --std=c++2a --all-warnings --extra-warnings -Wno-address \
	-Werror -Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor \
	-Warray-bounds -Wattribute-alias -Wformat-overflow -Wformat-truncation \
	-Wmissing-attributes -Wstringop-truncation \
	-O1
	# -Wdeprecated-copy -Wclass-conversion \

tmp/%.o: %.cpp
	$(CXX) $(FLAGS) -o $@ $< -lstdc++fs -lpthread
	./$@

tmp:
	mkdir -p $@

clean:
	rm -rf tmp *.bin *.out
