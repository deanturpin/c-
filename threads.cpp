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

  std::queue<std::string> files({
    "file1",
    "file2",
    "file3",
    "file4",
    "file5",
    "file6",
  });

  std::vector<std::thread> threads;

  while (!files.empty()) {
    const auto file = files.front();
    threads.push_back(std::thread(process_file, file));
    files.pop();

    std::cout << threads.size() << " threads\n";

    // If we've created enough threads wait for them
    // if (threads.size() == 1)
    //   for (auto &t : threads) {
    //     std::cout << *reinterpret_cast<unsigned int *>(&t) << " join\n";
    //     t.join();
    // }

    // And then clear down the threads
    // threads.clear();
  }

  for (auto &t : threads) {
    std::cout << *reinterpret_cast<unsigned int *>(&t) << " join\n";
    t.join();
  }

  return 0;
}
