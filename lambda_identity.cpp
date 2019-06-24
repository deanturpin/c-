#include <functional>

using param = const int &;
const std::vector<std::function<int(param)>> functions{
    [](param i) { return i * 0; }, [](param i) { return i * 1; },
    [](param i) { return i * 2; }, [](param i) { return i * 3; },
    [](param i) { return i * 4; }, [](param i) { return i * 5; },
    [](param i) { return i * 6; }, [](param i) { return i * 7; },
};

int main() {

  int sum = 0;
  for (int i = 0; i < 10000; ++i)
    for (const auto &f : functions)
      sum += f(i);
}
