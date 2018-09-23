#include <assert.h>
#include <string>

struct a {
  std::string identity() const { return "a"; }
};

struct b : virtual a {};
struct c : virtual a {};

struct d : b, c {};

int main() {

  d x;
  assert(x.identity() == "a");
}
