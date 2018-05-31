#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

int main() {

  using namespace std;

  istringstream iss("Don't look at the finger.");
  const vector<string> tokens{istream_iterator<string>{iss},
                              istream_iterator<string>{}};

  for (const auto &t : tokens)
    cout << t << '\n';
}
