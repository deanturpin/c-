#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <thread>
#include <vector>

// std::atomic<bool> ready (false);
// std::atomic_flag winner = ATOMIC_FLAG_INIT;

int main() {

  std::vector<std::string> files({
      "file0.txt", "file1.txt", "file2.txt", "file3.txt", "file4.txt",
      "file5.txt", "file6.txt", "file7.txt",
  });

  std::vector<std::thread> threads;

  const unsigned deep_end = std::thread::hardware_concurrency();

  for (auto f = files.cbegin(); f < files.cend();) {
    for (auto i = 0UL; i < deep_end; ++i) {

      const auto file = *f;

      threads.push_back(std::thread(
          [](const auto &f) { std::cout << "\t" << f << " lambda\n"; }, file));

      threads.back().join();
      if (++f >= files.cend())
        break;
    }

    std::cout << threads.size() << " threads cleared\n";
    threads.clear();
  }

  return 0;
}
