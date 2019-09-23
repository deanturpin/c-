files := $(wildcard *.cpp)
objects = $(files:%.cpp=tmp/%.o)

ifndef CXX
override FOO = g++-9
else
	@echo already set
endif

all: tmp
	@echo > output.md
	$(MAKE) -j $(shell nproc) $(objects)

CXXFLAGS ?= --std=c++2a --all-warnings --extra-warnings --pedantic-errors \
	-Werror -Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor \
	-Warray-bounds -Wattribute-alias -Wformat-overflow -Wformat-truncation \
	-Wmissing-attributes -Wstringop-truncation \
	-Wdeprecated-copy -Wclass-conversion \
	-O1

tmp/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< -lpthread
	@echo '```' >> output.md
	./$@ >> output.md
	@echo '```' >> output.md

tmp:
	mkdir -p $@

clean:
	rm -rf tmp *.bin *.out
