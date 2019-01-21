#include <iostream>
#include <iomanip>
#include <future>

auto main() -> int {

	auto name = std::async(
			[]{ return "blah"; }
			);

	std::cout << std::quoted(name.get()) << " is my name\n";
}
