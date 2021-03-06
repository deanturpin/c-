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

    // Error - candidate constructor (the implicit copy constructor) not
    // viable:
    // B("blah");
  }

  // Overload not override
  {
    class A {
    public:
      void foo() { cout << "foo\n"; }
    };

    class B : public A {
    public:
      void foo() const { cout << "bar\n"; }
    };

    cout << "Overload not override\n";
    A a;
    B b;

    a.foo();
    b.foo();
  }

  // final keyword 1
  {
    struct A {
      virtual void foo() final;
      void bar();
      virtual ~A() = default;
    };

    struct B final : public A {
      // Error - A::foo is final
      // void foo();

      void bar(){};
    };
  }

  // override keyword
  {
    class A {
      void foo();
      // virtual void bar();
    };

    class B : public A {
      void foo(){};
    };

    // A a;
    // B b;
  }
}
