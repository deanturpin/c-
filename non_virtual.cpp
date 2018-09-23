#include <assert.h>
#include <string>

// Virtual override
struct a {
  virtual std::string identity() const { return "a"; }
  virtual ~a() {}
};

struct b : a {
  std::string identity() const { return "b"; }
};

// Non-virtual override
struct c {
  std::string identity() const { return "c"; }
};

struct d : c {
  std::string identity() const { return "d"; }
};

int main() {
  a _a;
  b _b;
  c _c;
  d _d;

  assert(_a.identity() == "a");
  assert(_b.identity() == "b");
  assert(_c.identity() == "c");
  assert(_d.identity() == "d");

  assert(sizeof _a == 8);
  assert(sizeof _b == 8);
  assert(sizeof _c == 1);
  assert(sizeof _d == 1);
}
