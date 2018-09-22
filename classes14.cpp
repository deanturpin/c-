#include <iostream>

int main() {

  // is_final
  struct A {
    virtual void foo() final;
    void bar();

    virtual ~A() {}
  };

  struct B final : public A {
    // Error - A::foo is final
    // void foo();

    void bar() {}
  };

  std::cout << "Is A final? " << std::boolalpha << std::is_final<A>::value
            << ' ';
  std::cout << "Is B final? " << std::boolalpha << std::is_final<B>::value
            << '\n';

  return 0;
}
