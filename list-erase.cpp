#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

template <typename T> void print_and_erase(T container) {

  // Print container
  std::cout << "start\n";
  std::copy(container.cbegin(), container.cend(),
            std::ostream_iterator<int>(std::cout, "\n"));

  // Erase elements
  const auto middle = std::next(container.cbegin(), container.size() / 2);
  container.erase(middle, std::next(middle, 2));

  // Print it again
  std::cout << "erase\n";
  std::copy(container.cbegin(), container.cend(),
            std::ostream_iterator<int>(std::cout, "\n"));
}

int main() {

  // Create list of things
  std::list<int> l{1, 2, 3, 4, 5, 6};
  print_and_erase(l);

  // Create vector of things
  std::vector<int> v{1, 2, 3, 4, 5, 6};
  print_and_erase(v);

  // Create deque of things
  std::deque<int> d{1, 2, 3, 4, 5, 6};
  print_and_erase(d);
}
