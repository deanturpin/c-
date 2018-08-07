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
      {0b00011'11111'10000'00000, 0b0110}, // Block
      {0b10001'00000'00000'01000, 0b1100}, // Random
  };

  // Iterate over each test pair
  for (const auto & [ input, output ] : test_cases) {

    // Register used by both low- and high-frequency readers
    bool shared_register = false;

    // The high frequency reader process every state change
    const auto high_frequency_reader = [&shared_register]() {
      shared_register = true;
    };

    // The low frequency reader is called less often
    const auto low_frequency_reader = [&shared_register]() {

      const auto value = shared_register;
      shared_register = false;

      // Return the value to report
      return value;
    };

    // Create a container to compare with the expected results from the test
    // case
    std::bitset<4> results;

    // Iterate over each bit in the input sequence
    std::cout << input << " test\n" << output << " expected\n";
    for (size_t i = 0; i < input.size(); ++i) {

      // The high-frequency reader sets the shared register for each input bit
      if (input.test(i))
        high_frequency_reader();

      // The low-frequency reader checks the shared register less often
      if (!(i % 5))
        results[i / 5] = low_frequency_reader();
    }

    // Print results
    std::cout << results << " actual\n";
    std::cout << (results == output ? "PASS" : "FAIL") << "\n\n";
  }
}
