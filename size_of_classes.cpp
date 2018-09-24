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

  assert(sizeof _a == 1);
  assert(sizeof _b == 8);
  assert(sizeof _c == 8);
}
