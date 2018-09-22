#include <algorithm>
#include <iostream>
#include <vector>

// Lambda - anonymous functions
int main() {

  using namespace std;

  vector<int> vec{1, 2, 3};

  // Before
  for (const auto &v : vec)
    cout << v << '
';

        // Increment each element
        for_each(vec.begin(), vec.end(), [](int &n) { ++n; });

  // After
  for (const auto &v : vec)
  cout << v << '
';

      auto square_and_print = [](int n) {
    cout << n *n << '
'; }; square_and_print(4);

        int blah = 2;

    // Lambda capture
    auto doubleit = [blah] { return blah * blah; };
    auto doubled = doubleit();
    cout << doubled << '
';

        auto doubleit2 = [blah]() -> double { return blah * blah; };
    auto doubled2 = doubleit2();
    cout << doubled2 << '
';
  }
