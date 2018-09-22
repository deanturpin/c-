#include <iostream>

class base {
public:
  virtual ~base() {}
  virtual void blah() { std::cout << "base\n"; }
};

class derived : base {
public:
  ~derived() {}
  void blah() { std::cout << "derived\n"; }
};

int main() {

  base b;
  derived d;

  b.blah();
  d.blah();
}
