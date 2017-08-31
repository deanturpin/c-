#include <iostream>
#include <memory>

namespace wood {
using namespace std;

class Animal {
public:
  Animal(const string n) : name(n) { cout << "ctor " << name << endl; }

  ~Animal() { cout << "\tdtor " << name << endl; }

  const string name;
};
}

int main() {
  using namespace std;
  using namespace wood;

  const auto a = shared_ptr<Animal>(new Animal("a"));
}
