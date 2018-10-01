#include <algorithm>
#include <cassert>
#include <iostream>
#include <thread>
#include <vector>

// std::atomic<bool> ready (false);
// std::atomic_flag winner = ATOMIC_FLAG_INIT;

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

  const auto dump = [](const std::string title, const auto &cont) {
    std::cout << title << '\n';
    for (const auto &x : cont)
      std::cout << x << '\n';
  };

  dump("ORIGINAL", a);

  const auto serial = [](auto &element) { element *= 2.0; };

  const auto parallel = [thread_count = 1](auto &i) {
    static std::vector<std::thread> threads;

    // if (threads.size() < threads)
    auto thr = std::thread([&i]() { i *= 2.0; });
    thr.join();
  };

  for_each(b.begin(), b.end(), serial);
  dump("SINGLE THREAD", b);

  for_each(c.begin(), c.end(), parallel);
  dump("MULTI THREAD", c);

  assert(b == c && "serial and parallel results differ");

  // const unsigned deep_end = std::thread::hardware_concurrency();

  // for (auto f = files.cbegin(); f < files.cend();) {
  //   for (auto i = 0UL; i < deep_end; ++i) {

  //     const auto file = *f;

  //     threads.push_back(std::thread(
  //         [](const auto &f) { std::cout << "\t" << f << " lambda\n"; },
  //         file));

  //     threads.back().join();
  //     if (++f >= files.cend())
  //       break;
  //   }

  //   std::cout << threads.size() << " threads cleared\n";
  //   threads.clear();
  // }
}
