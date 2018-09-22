#include <iostream>
#include <memory>

namespace wood {
using namespace std;

class Animal {
public:
  Animal(const string n) : name(n) {
    cout << "ctor " << name << '
'; }

        ~Animal() {
      cout << "\tdtor " << name << '
'; }

          const string name;
    };
  } // namespace wood

  int main() {
    using namespace std;
    using namespace wood;

    const auto a = unique_ptr<Animal>(new Animal("a"));

    // Using reset
    auto b = unique_ptr<Animal>(new Animal("b1"));

    // Call dtor for b1
    b.reset(new Animal("b2"));

    // Call dtor for b2
    b.reset();

    auto c = unique_ptr<Animal>(new Animal("c"));

    // Assignment calls dtor
    c = 0;

    auto d = unique_ptr<Animal>(new Animal("d"));

    // Release doesn't call the dtor but relinquishes responsibility
    auto e = d.release();

    cout << "d is a pointer " << boolalpha << is_pointer<Animal *>() << '
';

        // Delete d manually
        delete e;

    auto f = unique_ptr<int[]>(new int[5]());
    // cout << "Size of array " << f << '
    ';

        return 0;
  }
