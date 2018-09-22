#include <iostream>

class a {
public:
  a() { std::cout << "a ctor\n"; }
  ~a() { std::cout << "\ta dtor\n"; }
  void blah() { std::cout << "base\n"; }
};

int main() {

  // Create array of base class and delete them
  a *_a = new a[5];

  // Error - only calls destructor for first element
  // delete _a;

  delete[] _a;

  return 0;
}
