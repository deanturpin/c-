#include <iostream>
#include <fstream>
#include <thread>
#include <list>
#include <vector>
#include <queue>

// std::atomic<bool> ready (false);
// std::atomic_flag winner = ATOMIC_FLAG_INIT;

void process_file(const std::string name) {

  // std::ofstream out(name);
  // if (out)
  //   out << name;

  std::cout << name << "\n";
}

int main() {

  const unsigned deep_end = std::thread::hardware_concurrency();
  std::cout << deep_end << " threads available\n";

  std::vector<std::string> files({
    "file0.txt",
    "file1.txt",
    "file2.txt",
    "file3.txt",
    "file4.txt",
    "file5.txt",
    "file6.txt",
    "file7.txt",
  });

  std::vector<std::thread> threads;

  for (auto f : files) {
    for (auto i = 0UL; i < deep_end; ++i) {

      if (files.empty())
        break;

      const auto file = files.back();

      threads.push_back(
        std::thread([](const auto &f){ std::cout << f << " lambda\n"; }, file)
        );

      threads.back().join();

      files.pop_back();
    }

    std::cout << "Clear down the threads\n";

    // std::cout << "Clear down the threads\n";
    // threads.clear();
  }

  std::cout << threads.size() << " threads created\n";

  /*
  for (const auto &file : files) {

    // const auto file = files.back();
    // threads.push_back(std::thread(process_file, file));
    threads.push_back(
      std::thread([](const auto &f){ std::cout << f << " lambda\n"; }, file)
      );
    // files.pop_back();

    // std::cout << threads.size() << " threads\n";

    // If we've created enough threads wait for them
    if (threads.size() == 1)
      for (auto &t : threads) {
        std::cout << file << " join\n";
        t.join();
        std::cout << file << " joined\n";
    }

    std::cout << "All joined up\n";

    // And then clear down the threads
    threads.clear();
  }

  std::cout << threads.size() << " threads created\n";

  // for (auto &t : threads) {
  //   std::cout << *reinterpret_cast<unsigned int *>(&t) << " join\n";
  //   t.join();
  // }
  */

  return 0;
}
