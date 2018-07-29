#include <iostream>
#include <mutex>
#include <thread>

int main() {

  const size_t deep_end = std::thread::hardware_concurrency();
  puts((std::to_string(deep_end) + " max threads").c_str());

  // Common main for each thread
  const auto thread_main = [](const std::string &name,
                              const bool mut = true) -> void {

    const auto mutex_print = [&mut](const std::string &str) {
      static std::mutex printing;
      if (mut)
        printing.lock();
      for (const auto &word : {str.c_str(), "is", "my", "name", "yes", "it",
                               "is", "oh", "yes", "it", "is", "\n"})
        std::cout << ' ' << word;
      if (mut)
        printing.unlock();
    };

    long counter = 0;
    while (counter++ < 4) {
      using namespace std::chrono_literals;
      mutex_print(name);
      std::this_thread::sleep_for(1000ms);
    }
  };

  // Run with and without mutex print enabled
  for (const auto &m : {false, true}) {
    std::cout << std::boolalpha << m << " mutex\n";
    std::thread a(thread_main, "A", m);
    std::thread b(thread_main, "B", m);
    std::thread c(thread_main, "C", m);
    std::thread d(thread_main, "D", m);
    a.join();
    b.join();
    c.join();
    d.join();
  }
}
