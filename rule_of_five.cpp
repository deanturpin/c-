#include <cstdio>
#include <vector>

struct A {
  A() { puts("1. A()"); }
  A(const A &) { puts("2. A(const A &)"); }
  A(A &&) { puts("3. A(A &&)"); }
  A &operator=(const A &) {
    puts("4. A &operator=(A &)");
    return *this;
  }
  A &operator=(A &&) {
    puts("5. A &operator=(A &&)");
    return *this;
  }
  ~A() { puts("6. ~A()"); }
};

int main() {
  std::vector<A>().emplace_back(A()) = [a = A()]() mutable {
	  const auto _a = a;
	  return a = _a;
  }();
}
