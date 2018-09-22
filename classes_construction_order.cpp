#include <iostream>

void order() {

  using namespace std;

  cout << "Order" << '
';

      class A {

  public:
    A() {
      cout << "A" << ' '; } ~A(){cout << "~A" << '
'; } };

          class B : public A {

      public:
        B() {
          cout << "B" << ' '; } ~B(){cout << "~B" << '
'; } };

              cout
               << "Static allocation" << '
'; { B b; }

              cout
               << "Dynamic allocation - leak (A has non-virtual destructor)" << '
'; A *a = new B(); delete a;

          cout << "Array of pointers" << '
';

              A *b = new A[4];

          delete[] b;
        }

        void overload() {

          using namespace std;

          cout << "Overload" << '
';

              class A {

          public:
            void foo() {
              cout << "foo" << '
'; } };

                  class B : public A {

              public:
                void foo() const {
                  cout << "bar" << '
'; } };

                      class B b;
                  b.foo();
                }

                // Order of contruction/destruction
                int main() {

                  order();
                  overload();

                  return 0;
                }
