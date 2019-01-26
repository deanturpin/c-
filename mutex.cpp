#include <iostream>
#include <mutex>
#include <thread>

int main() {

  const size_t max_threads = std::thread::hardware_concurrency();
  std::cout << max_threads << " max threads\n";

  // Control printing to screen
  std::mutex printing;

  // A considerate printing routing that waits its turn
  const auto mutex_print = [&printing](const std::string &str,
                                       const bool mutex_print_enabled) {
    // Try to take the mutex
    if (mutex_print_enabled)
      printing.lock();

    // Print something to the screen in a leisurely fashion
    for (const auto &word : {str.c_str(), "is", "my", "name", "yes", "it", "is",
                             "oh", "yes", "it", "is", "\n"})
      std::cout << ' ' << word;

    // Release the mutex
    if (mutex_print_enabled)
      printing.unlock();
  };

  // Common main for each printing thread
  const auto thread_main = [&mutex_print](const std::string &name,
                                          const bool mutex_print_enabled) {
    long counter = 0;
    while (counter++ < 4) {

      // Print thread info and some other bits
      mutex_print(name, mutex_print_enabled);

      // And wait for a bit
      using namespace std::chrono_literals;
      std::this_thread::sleep_for(1000ms);
    }
  };

  // Run with and without mutex print enabled and see what gets printed to the
  // terminal
  for (const auto &mutex_print_enabled : {false, true}) {

    std::cout << "### " << std::boolalpha << mutex_print_enabled
              << " mutex\n\n";

    // Launch some threads
    std::thread a(thread_main, "A", mutex_print_enabled);
    std::thread b(thread_main, "B", mutex_print_enabled);
    std::thread c(thread_main, "C", mutex_print_enabled);
    std::thread d(thread_main, "D", mutex_print_enabled);

    // Wait for threads to finish
    a.join();
    b.join();
    c.join();
    d.join();
  }
}
