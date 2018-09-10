#include <iostream>
#include <string>
#include <vector>

int main() {

  std::vector<std::string> blah = {"d", "a", "b", "c", "d"};
  for (const auto &a : blah) {

    if (a == *blah.crbegin())
      std::cout << "*\n";

    std::cout << std::addressof(a) - std::addressof(blah[0]) << '\t' << a
              << '\n';
  }
}
