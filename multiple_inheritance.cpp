#include <assert.h>
#include <string>

// Base classes
struct a {
  const std::string id = "a";
};
struct b {
  const std::string id = "b";
};

// Derived class
struct c : a, b {};

int main() {

  a _a;
  b _b;
  c _c;

  // Base class IDs
  assert(_a.id == "a");
  assert(_b.id == "b");

  // Derived class ID is ambigious
  assert(_c.a::id == "a");
  assert(_c.b::id == "b");
}
