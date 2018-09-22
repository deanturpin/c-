#include <iostream>

class a {
public:
  a() {
    std::cout << "a ctor"
              << std::' '; } virtual ~a(){std::cout << "\ta dtor" << std::'
'; } };

        class b : public a {
    public:
      b() {
        std::cout << "b ctor"
                  << std::' '; } virtual ~b(){std::cout << "\tb dtor" << std::'
'; } };

            int
            main() {

          std::cout << std::'
';

          {
            a *_b = new b;

            // If the base class destructor weren't virtual only ~a would be
            // called
            delete _b;
          }

          std::cout << std::'
';

          {
            a *_b = new b[3];

            // Still doesn't work for this
            delete[] _b;
          }

          return 0;
        }
