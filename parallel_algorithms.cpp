#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

template <typename Iterator, typename Functor>
void for_each_par(Iterator begin, Iterator end, Functor func) {

  const auto thread_count = std::thread::hardware_concurrency();
  const auto total_elements = std::distance(begin, end);
  const unsigned long elements_per_thread =
      std::ceil(1.0 * total_elements / thread_count);

  // Partition data for each thread
  std::cout << thread_count << " threads\n";
  std::cout << total_elements << " size\n";
  std::cout << elements_per_thread << " elements per thread\n";

  for (unsigned int i = 0; i < thread_count; ++i) {

    // Initialise iterators
    static auto front = begin;
    static auto back = std::min(std::next(front, elements_per_thread), end);

    // Process each partition
    for_each(front, back, func);
    front = back;
    back = std::min(std::next(front, elements_per_thread), end);
  }
}

int main() {

  std::vector<double> a(9); // 1e6 + 13);
  std::iota(a.begin(), a.end(), 0.0);

  // Create copies to work with
  auto b = a;
  auto c = a;

  const auto add_five = [](auto &element) { element += 5.0; };
  // const auto double_me = [](auto &element) { element *= 1.0; };

  for_each(b.begin(), b.end(), add_five);
  for (const auto &x : b)
    std::cout << x << '\n';

  for_each_par(c.begin(), c.end(), add_five);
  for (const auto &x : c)
    std::cout << x << '\n';

  assert(b == c && "serial and parallel results differ");
}
