#include <algorithm>
#include <iostream>
#include <vector>

// Lambda - anonymous functions
void lambda_functions() {
  using namespace std;

  vector<int> vec{1, 2, 3};

  // Before
  for (const auto &v : vec)
    cout << v << endl;

  // Increment each element
  for_each(vec.begin(), vec.end(), [](int &n) { ++n; });

  // After
  for (const auto &v : vec)
    cout << v << endl;

  auto square_and_print = [](int n) { cout << n * n << endl; };
  square_and_print(4);

  int blah = 2;

  // Lambda capture
  auto doubleit = [blah] { return blah * blah; };
  auto doubled = doubleit();
  cout << doubled << endl;

  auto doubleit2 = [blah]() -> double { return blah * blah; };
  auto doubled2 = doubleit2();
  cout << doubled2 << endl;
}
