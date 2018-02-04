#include <iostream>
#include <fstream>
#include <thread>
#include <vector>

void process_file(const std::string name) {

  std::ofstream out(name);
  if (out)
    out << name;
}

int main() {

  // std::thread first(foo1);
  // std::thread second(foo2);
  // std::thread third(foo3);
  // std::thread fourth(foo4);

  std::vector<std::string> files = {
    "file1",
    "file2",
    "file3",
    "file4",
    "file5",
  };

  std::thread blah(process_file, "blah.txt");

  blah.join();
  // second.join();
  // third.join();
  // fourth.join();

  return 0;
}
