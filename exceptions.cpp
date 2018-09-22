#include <iostream>
#include <vector>

int main() {

  // Simple
  try {
    throw 2;
  } catch (int e) {
    std::cout << "Caught exception " << e << '\n';
  }

  try {
    std::vector<int> vec(-1);
  } catch (std::exception &e) {
    std::cout << "Standard exception " << e.what() << '\n';
  }

  return 0;
}
