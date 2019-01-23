#include <cassert>

int main() {

  class a {
  } _a;

  struct b {
    virtual ~b() {}
  } _b;

  struct c : b {
    virtual ~c() {}
  } _c;

  struct d : a {
  } _d;

  assert(sizeof _a == 1);
  assert(sizeof _d == 1);
  assert(sizeof _b == 8);
  assert(sizeof _c == 8);
}
