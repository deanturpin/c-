#include <iostream>
#include <vector>

int main() try {

  size_t bytes = 35 * 100 * 1000 * 1010ul;
  std::vector<uint8_t> v(bytes);

  std::cout << v.size() << " size of container in bytes\n";
  std::cout << v.max_size() << " max size of container in bytes\n";

} catch (...) {
  std::cout << "Caught\n";
}
