#include <filesystem>

int main() {
  for (auto &p : std::filesystem::directory_iterator("."))
    std::puts(p.path().c_str());
}
