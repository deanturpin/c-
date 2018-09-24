#include <assert.h>
#include <memory>

int main() {

  class a {
  } z;

  struct b : public a {
    int id = 1;
  } w;

  const auto x1 = std::make_unique<a>();
  const auto x2 = std::make_shared<a>();
  const auto x3 = std::make_shared<b>();

  // The size of...

  // A unique pointer
  assert(sizeof x1 == 8);

  // A shared pointer
  assert(sizeof x2 == 16);
  assert(x3->id == 1);

  // An empty class
  assert(sizeof z == 1);

  // A derived class with a new member
  assert(sizeof w == 4);

  // Some built-in types
  assert(sizeof 0 == 4);
  assert(sizeof 0l == 8);
  assert(sizeof 0.0 == 8);
}
