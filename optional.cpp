#include <iostream>
#include <optional>
#include <vector>

int main() {

  std::vector<std::optional<long>> options{
      // Some entries are not initialised to a value
      {},
      1,
      2,
      3,
      {}};

  // Print all valid options
  for (const auto &o : options)
    if (o)
      std::cout << o.value() << '\n';
}
