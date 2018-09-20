#include <iostream>

int main() {

  using std::alignment_of;
  using std::cout;

  class A {};
  class alignas(32) B {};

  cout << "class A {};\n";
  cout << "class alignas(32) B {};\n\n";

  cout << alignment_of<A>::value << "\talignment_of<A>::value\n";
  cout << alignment_of<B>::value << "\talignment_of<B>::value\n";
  cout << alignment_of<int>::value << "\talignment_of<int>::value\n";
  cout << alignment_of<double>::value << "\talignment_of<double>::value\n";
  cout << alignof(A) << "\talignof(A)\n";
  cout << alignof(B) << "\talignof(B)\n";
  cout << alignof(int) << "\talignof(int)\n";
  cout << alignof(double) << "\talignof(double)\n";
}
