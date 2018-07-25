#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

struct A {
  A() { std::cout << "\t1. A()\n"; }
  A(const A &a) {
    std::cout << "\t2. A(const A &)\n";
    value = a.value;
  }
  A(A &&a) {
    std::cout << "\t3. A(A &&)\n";
    value = a.value;
  }

  A &operator=(const A &a) {
    std::cout << "\t4. A4\n";
    value = a.value;
    return *this;
  }
  A &operator=(A &&a) {
    std::cout << "\t5. A &operator=(A &&)\n";
    value = a.value;
    return *this;
  }

  ~A() { std::cout << "\t6. ~A() value " << value << '\n'; }

  long value = 0;
};

// template <typename Iter> std::vector<A> filter(Iter begin, Iter end) {
//   // std::decay_t<decltype(seq)> filt;
//   // std::copy_n(seq.cbegin(), seq.size() + 1, std::back_inserter(filt));
//   // return filt;
//   return std::vector<A>(begin, end);
// }

int main() {

  // const std::array<size_t, 3> seq(std::make_integer_sequence<size_t, 3>{});
  std::cout << "### INIT\n";

  std::cout << "Create some objects\n";
  std::vector<A> seq(2);
  // for (const auto &i : seq) std::cout << i.value << '\n';

  // std::cout << "Apply values to objects\n";
  long x = 0;
  for (auto &i : seq)
    i.value = ++x;
  // for (const auto &i : seq) std::cout << i.value << '\n';

  //   std::generate(seq.begin(), seq.end(),
  // 		  []() {
  //
  // 		  	static int i = 1;
  //
  // 		  	A a;
  // 			a.value = i++;
  // 			return a;
  // 		  });

  // {
  //   std::cout << "Emplace back an object\n";
  //   A a;
  //   a.value = 11;
  //   seq.emplace_back(a);
  //   for (const auto &i : seq) std::cout << i.value << '\n';
  // }

  std::cout << seq.capacity() << " initial capacity\n";
  {
    std::cout << "Push back an object\n";
    seq.emplace_back(A()) = []() {
      A a, b;
      a = b;
      return a;
    }();
  }

  std::cout << seq.capacity() << " new capacity\n";
  std::cout << "Final values\n";
  for (const auto &i : seq)
    std::cout << i.value << '\n';

// seq.emplace_back(A()); // .value = 10;
// std::cout << seq.size() << " items in seq\n";

// A a;
// a.value = 11;
// std::cout << "Copy in a new object\n";
// seq.emplace_back(a);

// for (const auto &i : seq) std::cout << i.value << '\n';

// std::copy(seq.cbegin(), seq.cend(), std::ostream_iterator<int>(std::cout,
// "\n"));
//
//
#if 0

  {
    std::cout << "### FILTER\n";
    const auto seq_filtered = filter(seq.cbegin(), seq.cend());
    std::cout << seq_filtered.size() << " items in seq_filtered\n";
  }

  {
    std::cout << "### REDUCE\n";
    const auto reducer = [](auto &sum, const auto &element) {
      return sum * 2 + 1 + element.value;
    };
    const auto reduced = std::accumulate(seq.cbegin(), seq.cend(), 0, reducer);
    std::cout << reduced << " reduced\n";
  }

#endif

  std::cout << "End of routine\n";
}
