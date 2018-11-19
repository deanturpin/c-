#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <thread>
#include <vector>

// VEKTOR - a concatenating vector
template <typename T> struct vektor : public std::vector<T> {

  // A constructor with a value pushes the value onto the empty vector
  explicit vektor(const T &a) { this->push_back(a); }

  // Ensure the default constuctor is valid
  vektor() = default;

  // Declare the concatenation operator overloads
  friend vektor operator+(vektor<T> &a, const T &b) {
    a.reserve(a.size() + 1);
    return a.push_back(b);
  }

  friend vektor operator+(vektor<T> &a, const vektor<T> &b) {
    a.reserve(a.size() + b.size());
    for (const auto &c : b)
      a.emplace_back(c);
    return a;
  }

  friend vektor operator+(vektor<T> &&a, const vektor<T> &b) {
    for (const auto &c : b)
      a.push_back(c);
    return std::move(a);
  }
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

  // Partition data for each thread
  using vek = vektor<worker_t>;
  const std::function<vek(Iterator, Iterator, double)> populate =
      [&populate, &calcs_per_thread, &end](const Iterator a, const Iterator b,
                                           const double n) {
        const auto c = std::min(std::next(b, calcs_per_thread), end);
        return n > 0.0 ? vek({a, b}) + populate(b, c, n - 1) : vek();
      };

  const vek workers = populate(
      begin, std::min(std::next(begin, calcs_per_thread), end), thread_count);

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
  std::vector<double> a(1e4 + 13);
  std::iota(a.begin(), a.end(), 1.1);

  // Create copies to work with
  auto b = a;
  auto c = a;

  // The worker routine
  const auto do_things = [](auto &i) { i = std::sqrt(i + 1.0 / 1000000); };

  // Serial application
  std::for_each(b.begin(), b.end(), do_things);

  // Parallel application
  parallel::for_each(c.begin(), c.end(), do_things);

  assert(b == c);
}
