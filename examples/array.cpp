#include <array>
#include <iostream>
#include <memory>

int main() {

  using namespace std;

  const unsigned int s = 1000;
  array<array<double, s>, s / 2> a;

  a[0][0] = 1;
  a.data()[0][0] = 1;

  cout << "Rows " << a.size() << endl;
  cout << "Cols " << a.front().size() << endl;

  // 1D array on the heap
  auto b = unique_ptr<array<int, 5>>(new array<int, 5>);
  cout << b.get()->at(0) << endl;

  // 2D array on the heap
  auto c = unique_ptr<array<array<int, 5>, 5>>(new array<array<int, 5>, 5>);

  return 0;
}
