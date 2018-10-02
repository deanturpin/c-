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
  std::cerr << thread_count << " threads\n";
  std::cerr << total_elements << " size\n";
  std::cerr << elements_per_thread << " elements per thread\n";

  thread_local std::vector<std::thread> threads;
  for (unsigned int i = 0; i < thread_count; ++i) {

    // Initialise iterators
    thread_local auto front = begin;
    thread_local auto back =
        std::min(std::next(front, elements_per_thread), end);

    // Process each partition
    threads.push_back(std::thread(
        [&func](auto f, auto b) {
          std::cerr << "start\n";
          for_each(f, b, func);
          std::cerr << "done\n";
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
  std::vector<double> a(1e8 + 13, 1.1);
  // std::iota(a.begin(), a.end(), 0.0);
  std::cout << "test vector complete\n";

  // Create copies to work with
  auto b = a;
  auto c = a;

  const auto double_me = [](auto &i) {
    i = std::sqrt(std::sqrt(10.0 + i * i * i * i));
  };

  // for_each(b.begin(), b.end(), double_me);
  // for (const auto &x : b)
  //   std::cout << x << '\n';

  for_each_par(c.begin(), c.end(), double_me);
  // for (const auto &x : c)
  //   std::cout << x << '\n';

  // assert(b == c && "serial and parallel results differ");
}
