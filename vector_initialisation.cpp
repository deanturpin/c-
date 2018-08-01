#include <iostream>
#include <vector>

int main() {

  const auto stats = [](const auto &container) {
    std::cout << container.size() << " size\n";
  };

  {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    stats(vec);
  }

  {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};
    stats(vec);
  }
}
