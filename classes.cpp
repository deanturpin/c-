#include <iostream>

int main() {

  using namespace std;

  // is_final
  struct A {
    virtual void foo() final {}
    void bar();

    virtual ~A() {}
  };

  struct B final : public A {
    // Error - A::foo is final
    // void foo();

    void bar(){};
  };

  cout << "Is A final? " << boolalpha << is_final<A>::value << ' ';
  cout << "Is B final? " << boolalpha << is_final<B>::value << '\n';
}
