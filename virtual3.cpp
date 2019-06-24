#include <iostream>

class a {
public:
  a() { std::cout << "a ctor\n"; }
  virtual ~a() { std::cout << "\ta dtor\n"; }
};

class b : public a {
public:
  b() { std::cout << "b ctor\n"; }
  virtual ~b() { std::cout << "\tb dtor\n"; }
};

int main() {

  std::cout << '\n';

  {
    a *_b = new b;

    // If the base class destructor weren't virtual only ~a would be
    // called
    delete _b;
  }

  std::cout << '\n';

  {
    a *_b = new b[3];

    // Still doesn't work for this
    delete[] _b;
  }
}
