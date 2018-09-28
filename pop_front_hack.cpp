#include <cassert>
#include <vector>

int main() {

  // Define test vector
  const std::vector<int> a{1, 2, 3, 4, 5};

  // Create a copy of it
  auto b = a;

  // Lambda function: copy the back to the front and pop the back
  const auto pop_front = [](auto &cont) {
    cont.front() = cont.back();
    cont.pop_back();
  };

  // Pop the front of our vector
  pop_front(b);

  // Check it's the correct length (ignore the order)
  assert(b.size() == a.size() - 1 && "pop fail");
}
