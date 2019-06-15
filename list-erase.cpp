#include <list>
#include <iterator>
#include <iostream>

int main() {

  // Create list of things
  std::list<int> l{1,2,3,4,5,6};
  std::cout << "start\n";
  std::copy(l.cbegin(), l.cend(), std::ostream_iterator<int>(std::cout, "\n"));

  // Erase one
  const auto middle = std::next(l.cbegin(), l.size() / 2);
  l.erase(middle, std::next(middle, 2));

  std::cout << "erase\n";
  std::copy(l.cbegin(), l.cend(), std::ostream_iterator<int>(std::cout, "\n"));
}
