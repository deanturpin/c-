#include <iostream>

void order() {

  using namespace std;

  cout << "Order\n";

  class A {

  public:
    A() { cout << "A" << ' '; }
    ~A() { cout << "~A\n"; }
  };

  class B : public A {

  public:
    B() { cout << "B" << ' '; }
    ~B() { cout << "~B\n"; }
  };

  cout << "Static allocation\n";
  { B b; }

  cout << "Dynamic allocation - leak (A has non-virtual destructor)\n";
  A *a = new B();
  delete a;

  cout << "Array of pointers\n";

  A *b = new A[4];

  delete[] b;
}

void overload() {

  using namespace std;

  cout << "Overload\n";

  class A {

  public:
    void foo() { cout << "foo\n"; }
  };

  class B : public A {

  public:
    void foo() const { cout << "bar\n"; }
  };

  class B b;
  b.foo();
}

// Order of contruction/destruction
int main() {

  order();
  overload();

  return 0;
}
