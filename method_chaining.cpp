// https://en.wikipedia.org/wiki/Method_chaining#C++

#include <iostream>

namespace my {
using namespace std;

class chain {
public:
  chain() { cout << "ctor" << endl; }
  ~chain() { cout << "dtor" << endl; }

  chain &strength(const bool s) {
    strong = s;
    return *this;
  }

  chain &length(const unsigned int l) {
    links = l;
    return *this;
  }

private:
  unsigned int links = 0;
  bool strong = false;
};
}

int main() {
  my::chain c;
  c.length(10).strength(false);
  return 0;
}
