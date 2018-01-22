#include <algorithm>
#include <iostream>
#include <vector>

int main() {

  using namespace std;

  for (const auto &i : {5, 4, 3})
    cout << "iter " << i << endl;

  vector<int> vec = {1, 2, 3};
  for_each(vec.begin(), vec.end(), [](auto &a) { ++a; });

  for (const auto &v : vec)
    cout << "cont " << v << endl;

  // Can't do this, tho...
  // int i;
  // for (i : vec)
  //   cout << "cont " << i << endl;

  return 0;
}
