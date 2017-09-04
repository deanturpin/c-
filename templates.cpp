#include <iostream>
#include <vector>

template <typename T> void square(T &container) {
  for (auto &c : container)
    c *= c;
}

int main() {

  using namespace std;

  vector<int> vec = {1, 2, 3};

  square(vec);
  for (const auto &v : vec)
    cout << v << endl;
}
