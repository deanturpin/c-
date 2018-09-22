#include <iostream>

class base {
public:
  virtual ~base() {}
  virtual void blah() {
    std::cout << "base"
              << std::'
'; } };

        class derived : base {
    public:
      ~derived() {}
      void blah() {
        std::cout << "derived"
                  << std::'
'; } };

            int
            main() {

          base b;
          derived d;

          b.blah();
          d.blah();
        }
