#include <iostream>

const bool return_builtin() { return true; }

struct rah {};

const rah return_userdefined() { return rah(); }

int main() {

  auto b = return_builtin();
  b = false;

  auto r = return_userdefined();
  r = rah();

  return b;
}
