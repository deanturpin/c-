#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

template <typename Iterator, typename Functor>
void for_each_par(Iterator begin, Iterator end, Functor func) {

  const unsigned thread_count = std::thread::hardware_concurrency();

  for (auto i = begin; i < end; i += thread_count) {

    std::vector<std::thread> threads;
    for (auto j = i; std::distance(i, j) < thread_count && j < end; ++j)
      threads.push_back(std::thread([&j, func]() { func(*j); }));

    for (auto &thr : threads)
      if (thr.joinable())
        thr.join();
  }
}

int main() {

  std::vector<double> a(1e6);
  std::iota(a.begin(), a.end(), 0.0);

  // Create copies to work with
  auto b = a;
  auto c = a;

  const auto double_me = [](auto &element) { element *= 2.0; };

  for_each(b.begin(), b.end(), double_me);
  for_each_par(c.begin(), c.end(), double_me);

  assert(b == c && "serial and parallel results differ");
}
