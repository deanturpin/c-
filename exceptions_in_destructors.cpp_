#include <iostream>
#include <vector>

struct A {};

auto main() -> int {

  try {
    std::vector<int> vec();
    A a;

    std::cout << sizeof a << '\n';
  } catch (std::exception &e) {
    std::cout << "Standard exception " << e.what() << '\n';
  }
}
