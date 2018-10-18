#include <iostream>
#include <vector>

struct copy_me {};

int main() {

  std::vector<copy_me> x;

  // Create a 2D array of objects
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)
      x.push_back(copy_me());

  std::cout << x.size() << " entries\n";
}
