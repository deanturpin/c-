#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

namespace parallel {

const auto thread_count = std::thread::hardware_concurrency();

template <typename Iterator, typename Functor>
void for_each(Iterator begin, Iterator end, Functor func) {

  const auto calculations = std::distance(begin, end);
  const unsigned long calculations_per_thread =
      std::ceil(1.0 * calculations / thread_count);

  struct worker_t {
    Iterator a{};
    Iterator b{};
  };

  std::vector<worker_t> workers;

  const std::function<void(Iterator, Iterator, int)> populate =
      [&workers, &begin, &end, &calculations_per_thread,
       &populate](const Iterator a, const Iterator b, const int n) {
        if (n == 0)
          return;

        workers.push_back({a, b});

        populate(b, std::min(std::next(b, calculations_per_thread), end),
                 n - 1);
      };

  populate(begin, std::min(std::next(begin, calculations_per_thread), end),
           thread_count);

  std::cout << workers.size() << " workers\n";

  for (const auto &w : workers)
    std::cout << std::distance(begin, w.a) << ' ' << std::distance(begin, w.b)
              << '\n';

  // Partition data for each thread

  std::vector<std::thread> threads;
  for (const auto &w : workers)
    threads.push_back(std::thread(
        [&func](auto f, auto b) { std::for_each(f, b, func); }, w.a, w.b));

  // Wait for all threads to finish
  for (auto &thr : threads)
    if (thr.joinable())
      thr.join();
}
} // namespace parallel

int main() {

  // Create some test data
  const std::vector<double> a(10e4 + 9);

  // Create copies to work with
  auto b = a;
  auto c = a;

  // The worker routine
  const auto do_things = [n = .1](auto &i) mutable {
    i = std::sqrt(i + n);
    n += n;
  };

  // Serial application
  std::for_each(b.begin(), b.end(), do_things);

  // Parallel application
  parallel::for_each(c.begin(), c.end(), do_things);

  assert(b == c);
}
