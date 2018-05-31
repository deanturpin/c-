#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

int main() {
  std::istringstream iss("Don't look at the finger.");

  const std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                        std::istream_iterator<std::string>{}};

  for (const auto &t : tokens)
    std::cout << t << '\n';
}
