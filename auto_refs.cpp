#include <cassert>

int main() {

  int x = 10;
  assert(x == 10);

  // Normal reference
  int &y = x;
  y = 20;
  assert(x == 20);
  assert(y == 20);

  // Auto decays to the base type (not a reference)
  auto z = y;
  ++z;
  assert(x == 20);
  assert(y == 20);
  assert(z == 21);

  // Auto reference
  auto &w = y;
  ++w;
  assert(x == 21);
  assert(y == 21);
  assert(z == 21);
  assert(w == 21);
}
