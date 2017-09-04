/*
- [Rule of
three](https://en.wikipedia.org/wiki/Rule_of_three_%28C%2B%2B_programming%29)
- Rule of five

- C++: Understand how rule of 5 (rule of 3 in pre-C++11) is the best way to
write exception-safe classes. Understand why it's a good idea even without
exceptions.

* function local variables are NOT accessible in the try handler.

- Nested try/catch blocks
- Ellipsis

# References
- https://akrzemi1.wordpress.com/2011/06/10/using-noexcept/
*/

#include <exception>
#include <iostream>
#include <vector>

// Note the braces
void exception1() try {

  int y = 2;
  throw 1;
} catch (int e) {
  std::cout << "Caught " << e << std::endl;
} catch (const std::out_of_range &oor) {
  std::cout << "Caught OOR\n" << oor.what() << std::endl;
} catch (const std::exception &e) {
  std::cout << "Caught " << e.what() << std::endl;
} catch (...) {
  std::cout << "Caught ellipsis" << std::endl;
}

void exception2() {

  using namespace std;

  // Simple
  try {
    throw 2;
  } catch (int e) {
    cout << "Caught exception " << e << endl;
  }

  try {
    vector<int> vec(5);
    vec.at(6);
  } catch (exception &e) {
    cout << "Caught exception " << e.what() << endl;
  }
}

int main() {

  exception1();
  exception2();
  return 0;
}
