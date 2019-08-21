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

  thread_local std::vector<std::thread> threads;
  for (unsigned int i = 0; i < thread_count; ++i) {

    // Initialise iterators
    thread_local auto front = begin;
    thread_local auto back =
        std::min(std::next(front, elements_per_thread), end);

    // Process each partition
    threads.push_back(std::thread(
        [&func](auto f, auto b) {
          std::cout << "start\n";
          for_each(f, b, func);
          std::cout << "done\n";
        },
        front, back));

    front = back;
    back = std::min(std::next(front, elements_per_thread), end);
  }

  for (auto &thr : threads)
    if (thr.joinable())
      thr.join();
}

int main() {

  std::cout << "create test vector\n";
  std::vector<double> a(1e5 + 13, 1.1);
  std::cout << "test vector complete\n";

  // Create copies to work with
  auto b = a;
  auto c = a;

  // A busy routine
  const auto get_busy = [](auto &i) {
    i = std::sqrt(std::sqrt(10.0 + i * i * i * i));
  };

  // Update one copy with standard for loop and the other with the parallel
  // implementation
  for_each(b.begin(), b.end(), get_busy);
  for_each_par(c.begin(), c.end(), get_busy);

  assert(b == c && "serial and parallel results differ");
}
