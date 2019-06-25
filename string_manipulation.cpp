#include <cassert>
#include <iomanip>
#include <sstream>

int main() {

  std::stringstream s;
  std::string blah(std::to_string(1234));
  s << quoted(blah);

  assert(s.str() == "\"1234\"");
}
