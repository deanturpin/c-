#include <iostream>
#include <vector>

int main() {

  std::vector<int> v{1, 2, 3, 4};
  // std::vector<int&&> v2{int(0)};

  [[maybe_unused]] int &&x = int(0);

  // for (int i : v)
  //   v2.push_back(&i);

  for (int &i : v)
    std::cout << i << "\n";
}
