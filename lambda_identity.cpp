#include <functional>

const std::vector<std::function<int(const int &)>> functions{
    [](const int &i) { return i * 0; }, [](const int &i) { return i * 1; },
    [](const int &i) { return i * 2; }, [](const int &i) { return i * 3; },
    [](const int &i) { return i * 4; }, [](const int &i) { return i * 5; },
    [](const int &i) { return i * 6; }, [](const int &i) { return i * 7; },
};

int main() {

  std::vector<int> results;
  for ([[maybe_unused]] int i = 0; i < 10000; ++i)
    for (const auto &f : functions)
      results.push_back(f(i));

  return 0 && results.size();
}
