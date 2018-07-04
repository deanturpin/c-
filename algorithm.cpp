#include <algorithm>
#include <iostream>
#include <vector>

int main() {

  using namespace std;
  const vector<long> vec = {1, 2, 3, 4, 5, 6};
  const auto count =
      count_if(vec.cbegin(), vec.cend(), [](const auto &a) { return a < 3; });

  cout << count << endl;

  return 0;
}
