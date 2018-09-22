#include <iostream>

int main() {

  using namespace std;

  // Class to monitor consstruction/destruction
  class B {

  public:
    B() {
      cout << "B ctor" << ' '; } ~B(){cout << "B dtor" << '
'; } };

          // Class with no explicit constructors nor destructor
          class A {

        B b;

      public:
        // Prefix
        A &operator++() {
          cout << "++A" << '
'; return *this; }

                  // Postfix
                  A &
              operator++(int){cout << "A++" << '
'; return *this; } };

          // Create some instances
          cout << "Implicit constructors" << '
'; { A a;
          A b(a);
          A c = a;
        }

        cout << "\nOperator overloading" << '
'; A d; ++d;
        d++;

        return 0;
      }
