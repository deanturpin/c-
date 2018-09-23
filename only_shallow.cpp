#include <assert.h>
#include <memory>

int main() {

  class a {
  } z;

  class b : public a {
    int sdf;
  } w;

  const auto x = std::make_unique<a>();
  const auto y = std::make_shared<a>();

  // The size of...

  // A unique pointer
  assert(sizeof x == 8);

  // A shared pointer
  assert(sizeof y == 16);

  // An empty class
  assert(sizeof z == 1);

  // A derived class with a new member
  assert(sizeof w == 4);

  // Some built-in types
  assert(sizeof 0 == 4);
  assert(sizeof 0l == 8);
  assert(sizeof 0.0 == 8);
}
