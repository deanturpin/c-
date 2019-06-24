#include <array>
#include <iostream>
#include <memory>

int main() {

  const size_t s = 1000;
  std::array<std::array<double, s>, s / 2> a;

  a[0][0] = 1;
  a.data()[0][0] = 1;

  std::cout << "Rows " << a.size() << " ";
  std::cout << "Cols " << a.front().size() << "\n";

  // 1D array on the heap
  auto b = std::unique_ptr<std::array<int, 5>>(new std::array<int, 5>);
  std::cout << b.get()->at(0) << "\n";

  // 2D array on the heap
  auto c = std::unique_ptr<std::array<std::array<int, 5>, 5>>(
      new std::array<std::array<int, 5>, 5>);
}
