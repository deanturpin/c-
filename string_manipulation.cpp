#include <iostream>
#include <sstream>
#include <iomanip>

int main() {

  using namespace std;

  stringstream s;
  string blah(to_string(1234));
  s << quoted(blah);

  cout << s.str() << endl;

  return 0;
}
