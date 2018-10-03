#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <thread>
#include <vector>

// Concatenation wrapper
template <typename T = double> struct concat {

  concat &self() { return *this; }
  // concat& concat (const T a) {
  // 	container.push_back(a);
  // 	return *this; }

  concat() = default;

  concat(const T &a) { container.push_back(a); }

  std::vector<T> container{};

  friend concat &operator<<(concat<T> &a, const T &b) {
    a.container.push_back(b);
    return a;
  }

  friend concat &operator<<(concat<T> &a, const concat<T> &b) {
    for (const auto &c : b.container)
      a.container.push_back(c);
    return a;
  }

  friend concat &operator<<(concat<T> &&a, const concat<T> &b) {
    for (const auto &c : b.container)
      a.container.push_back(c);
    return a;
  }

  // friend std::vector<T> &operator=(const concat<double> &a) {
  //   return a.container;
  // }
};

namespace parallel {

const auto max_threads = std::thread::hardware_concurrency();

template <typename Iterator, typename Functor>
void for_each(Iterator begin, Iterator end, Functor func) {

  const auto calcs = std::distance(begin, end);
  const auto thread_count = calcs < max_threads ? 1 : max_threads;
  const unsigned long calcs_per_thread = std::ceil(1.0 * calcs / thread_count);

  struct worker_t {
    Iterator a{};
    Iterator b{};
  };

  // const auto blah2 = blah.container;
  const std::function<concat<double>(int)> generate =
      [&generate](const unsigned int n) {
        static concat<double> blah;

        if (n == 0)
          return blah;

        return blah << generate(n - 1);
      };

  // const auto blah2 = generate(3);
  // const auto blah2 =
  //         concat<double>().self() << (concat<double>().self() << 1.0 << 2.1
  //         << 4.5);
  // std::cout << blah2.container.size() << " blah2 size\n";
  // for (const auto &x : blah2.container) std::cout << x << '\n';

  using typ = concat<double>;
  const typ blah5 = typ(4) << typ(6) << 5.0 << typ(7);

  std::cout << blah5.container.size() << " blah5 size\n";
  for (const auto &x : blah5.container)
    std::cout << x << '\n';

  const std::function<std::string(int)> string_gen =
      [&string_gen](const int n) {
        if (n == 0)
          return std::string();

        return std::string("A") + string_gen(n - 1);
      };

  const auto strg = string_gen(4);
  std::cout << strg << '\n';

  // Partition data for each thread
  std::vector<worker_t> workers;
  const std::function<void(Iterator, Iterator, int)> populate =
      [&workers, &begin, &end, &calcs_per_thread,
       &populate](const Iterator a, const Iterator b, const int n) {
        if (n == 0)
          return;

        workers.push_back({a, b});
        const auto c = std::min(std::next(b, calcs_per_thread), end);
        populate(b, c, n - 1);
      };

  populate(begin, std::min(std::next(begin, calcs_per_thread), end),
           thread_count);

  std::cout << "WORKERS\n";
  std::cout << workers.size() << " workers\n";

  std::vector<std::thread> threads;
  for (const auto &w : workers) {
    std::cout << std::distance(begin, w.a) << ' ' << std::distance(begin, w.b)
              << '\n';
    threads.push_back(std::thread(
        [&func](auto f, auto b) { std::for_each(f, b, func); }, w.a, w.b));
  }

  // Wait for all threads to finish
  for (auto &thr : threads)
    if (thr.joinable())
      thr.join();
}
} // namespace parallel

int main() {

  // Create some test data
  std::vector<double> a(1e4);
  std::iota(a.begin(), a.end(), 1.1);

  // Create copies to work with
  auto b = a;
  auto c = a;

  // The worker routine
  const auto do_things = [](auto &i) { i = std::sqrt(i + 1.0 / 1000000); };

  // Serial application
  std::for_each(b.begin(), b.end(), do_things);
  // std::cout << "SERIAL\n";
  // std::copy(b.begin(), b.end(), std::ostream_iterator<double>(std::cout,
  // "\n"));

  // Parallel application
  parallel::for_each(c.begin(), c.end(), do_things);
  // std::cout << "PARALLEL\n";
  // std::copy(c.begin(), c.end(), std::ostream_iterator<double>(std::cout,
  // "\n"));

  assert(b == c);
}
