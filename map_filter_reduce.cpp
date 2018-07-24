#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct A {
	A() { std::cout << "A1\n"; }
	A(const A&) { std::cout << "A2\n"; }
	A(A&&) { std::cout << "A3\n"; }
	A& operator=(const A&) { std::cout << "A4\n"; return *this; }
	A& operator=(A&&) { std::cout << "A5\n"; return *this; }
	~A() { std::cout << "~A()\n"; }

	int value = 0;
};

template <typename Iter>
std::vector<A> filter(Iter begin, Iter end){
	// std::decay_t<decltype(seq)> filt;
	// std::copy_n(seq.cbegin(), seq.size() + 1, std::back_inserter(filt));
	// return filt;
	return std::vector<A>(begin, end);
}

int main() {

	// const std::array<size_t, 3> seq(std::make_integer_sequence<size_t, 3>{});
	const std::vector<A> seq{5};
	std::cout << seq.size() << " items in seq\n";

	// for (const auto &i : seq)
	// 	std::cout << "I am A\n";

	// std::copy(seq.cbegin(), seq.cend(), std::ostream_iterator<int>(std::cout, "\n"));

	{
		std::cout << "### FILTER\n";
		const auto seq_filtered = filter(seq.cbegin(), seq.cend());
		std::cout << seq_filtered.size() << " items in seq_filtered\n";
	}

	{
		std::cout << "### REDUCE\n";
	const auto reducer =
		[](auto &sum, const auto &element){ return sum + element.value;};
	const auto reduced = std::accumulate(seq.cbegin(), seq.cend(), 0, reducer);
	std::cout << reduced << " reduced\n";
	}

}
