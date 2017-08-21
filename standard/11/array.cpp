#include <iostream>
#include <array>

int main() {

  using namespace std;

  const unsigned int s = 1000;
  array<array<double, s>, s / 2> a;

  a[0][0] = 1;
  a.data()[0][0] = 1;

  cout << "Rows " << a.size() << endl;
  cout << "Cols " << a.front().size() << endl;

  return 0;
}
