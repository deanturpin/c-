#include <chrono>
#include <iostream>

int main() {

  std::cout << R"((?:[0-9]{1,3}\.?){4}\s+\S+)" << '\n';
  std::cout << 1'000'000'000 << '\n';
  std::cout << std::hex << 0x0000'1111'2222'3333 << std::dec << '\n';
  std::cout << std::hex << 0b0000011100001111 << std::dec << '\n';

  // Time related
  using namespace std;
  auto time1 = 90s;
  auto time2 = 1min;
  auto time3 = time1 + time2;

  std::cout << "Total time " << time3.count() << '\n';

  // template <char...> double operator "" _π(); // OK

  return 0;
}
