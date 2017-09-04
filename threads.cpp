// http://www.cplusplus.com/reference/thread/thread/

#include <iostream>
#include <thread>
#include <vector>

std::vector<double> arr(1e8); // = new int[1e6];

const unsigned int threads = 4;

void foo1() {

  for (unsigned int i = 0; i < arr.size(); i += threads) {
    arr.at(i) *= arr.at(i);
    arr.at(i) *= arr.at(i);
  }
}

void foo2() {

  for (unsigned int i = 1; i < arr.size(); i += threads)
    arr.at(i) *= arr.at(i);
}

void foo3() {

  for (unsigned int i = 2; i < arr.size(); i += threads)
    arr.at(i) *= arr.at(i);
}

void foo4() {

  for (unsigned int i = 3; i < arr.size(); i += threads)
    arr.at(i) *= arr.at(i);
}

int main() {

  using namespace std;

  thread first(foo1);
  thread second(foo2);
  thread third(foo3);
  thread fourth(foo4);

  first.join();
  second.join();
  third.join();
  fourth.join();

  return 0;
}
