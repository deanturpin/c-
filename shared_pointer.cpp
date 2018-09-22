#include <iostream>
#include <memory>

namespace wood {
using namespace std;

class Animal {
public:
  Animal(const string n) : name(n) { cout << "ctor " << name << '\n'; }

  ~Animal() { cout << "\tdtor " << name << '\n'; }

  const string name;
};
} // namespace wood

int main() {
  using namespace std;
  using namespace wood;

  const auto a = shared_ptr<Animal>(new Animal("a"));
}
