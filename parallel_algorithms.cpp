#include <algorithm>
#include <cassert>
#include <iostream>
#include <thread>
#include <vector>

template <typename Iterator, typename Functor>
void for_each_par(Iterator begin, Iterator end, Functor func) {
  std::for_each(begin, end, func);
}

int main() {

  // Create some test data
  const std::vector<double> a{
      0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0,
  };

  // Create copies to work with
  auto b = a;
  auto c = a;

  const unsigned thread_count = std::thread::hardware_concurrency();

  std::cout << a.size() << " elements\n";
  std::cout << thread_count << " threads available\n";

  const auto double_me = [](auto &element) { element *= 2.0; };

  std::vector<std::thread> threads;

  /*
  const auto parallel = [&threads, thread_count = 4u](auto &i) {
    if (threads.size() >= thread_count) {
      for (auto &t : threads) {
        std::cout << "join\n";
        t.join();
      }

      std::cout << "clear down\n";
      threads.clear();
    } else
      std::cout << threads.size() << " threads\n";

    threads.push_back(std::thread([&i]() { i *= 2.0; }));
  };
  */

  for_each(b.begin(), b.end(), double_me);
  for_each_par(c.begin(), c.end(), double_me);

  assert(b == c && "serial and parallel results differ");
}
