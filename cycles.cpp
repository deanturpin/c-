#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int main() {

  // A test consists of a pair of input and output bitsets
  using test = std::pair<std::bitset<20>, std::bitset<4>>;
  const std::vector<test> test_cases{
      {0b00000'00000'00000'00000, 0b0000}, // No bits set
      {0b11111'11111'11111'11111, 0b1111}, // All bits set
      {0b10101'01010'10101'01010, 0b1111}, // Alternate
      {0b00011'11111'11110'00000, 0b0000}, // Block
      {0b10001'00000'00000'01000, 0b1100}, // Random
  };

  // Register used by both low- and high-frequency readers
  bool shared_register = false;

  // Iterate over each test pair
  for (const auto & [ input, output ] : test_cases) {
    std::cout << input << '\n' << output << '\n';

    std::bitset<4> results;

    // Iterate over each bit in the input sequence
    for (size_t i = 0; i < input.size(); ++i) {

      // The high-frequency reader sets the shared register for each input bit
      if (input.test(i))
        shared_register = true;

      // The low-frequency reader checks the shared register less often
      if (!(i % 5)) {
        results.set(i / 5, shared_register);
        shared_register = false;
      }
    }

    // Print results
    std::cout << results << '\n';
    std::cout << (results == output ? "PASS" : "FAIL") << "\n\n";
  }
}
