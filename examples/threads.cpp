// http://www.cplusplus.com/reference/thread/thread/

#include <iostream>
#include <thread>

void foo() {

  std::cout << "foo" << std::endl;
}

void bar() {
  std::cout << "bar" << std::endl;
}

int main() {

  using namespace std;

  thread first(foo);
  thread second(bar);

  first.join();
  second.join();

  return 0;
}
