#include <iostream>

int main() {
  using namespace std;

  // Explicit
  {
    struct A {
      A(int) { ; }
    };

    struct B {
      explicit B(int) { ; }
    };

    A(1);
    B(1);

    // Error - candidate constructor (the implicit copy constructor) not viable:
    // B("blah");
  }

  // Overload not override
  {
    class A {
    public:
      void foo() { cout << "foo" << endl; }
      void foo() const { cout << "foo" << endl; }
    };

    class B : public A {
    public:
      void foo() const { cout << "bar" << endl; }
    };

    cout << "Overload not override" << endl;
    A a;
    B b;

    a.foo();
    b.foo();
  }

  return 0;
}
