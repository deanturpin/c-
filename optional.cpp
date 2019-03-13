#include <iostream>
#include <optional>
#include <vector>

int main() {

  // Some entries are not initialised to a value
  std::vector<std::optional<long>> options{{}, 1, 2, 3, {}};

  // Print all valid options
  for (const auto &o : options)
    if (o)
      std::cout << o.value() << '\n';

  // Print all valid options (using a default if not initialised)
  for (const auto &o : options)
    std::cout << o.value_or(-1) << '\n';
}
