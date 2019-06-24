#include <iostream>

void order() {

  std::cout << "Order\n";

  class A {

  public:
    A() { std::cout << "A"; }
    ~A() { std::cout << "~A"; }
  };

  class B : public A {

  public:
    B() { std::cout << "B"; }
    ~B() { std::cout << "~B"; }
  };

  std::cout << "\nStatic allocation\n";
  { B b; }

  std::cout << "\nDynamic allocation - leak (A has non-virtual destructor)\n";
  A *a = new B();
  delete a;

  std::cout << "\nArray of pointers\n";

  A *b = new A[4];

  delete[] b;
}

void overload() {

  std::cout << "\nOverload\n";

  class A {

  public:
    void foo() { std::cout << "foo\n"; }
  };

  class B : public A {

  public:
    void foo() const { std::cout << "bar\n"; }
  };

  class B b;
  b.foo();
}

// Order of contruction/destruction
int main() {

  order();
  overload();
}
