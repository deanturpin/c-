#include <cassert>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

int main() {

  // Create the public key for sharing
  const auto generate_public_key = [](const auto seed,
                                      const auto base) constexpr {
    return std::lrint(std::pow(base, seed)) %
           0b11111111'11111111'11111111'11111110;
  };

  // Generate and exchange keys
  const auto a{5ul};
  const auto b{4ul};
  const auto A{generate_public_key(a, 5)};
  const auto B{generate_public_key(b, 5)};
  const auto s1{generate_public_key(A, B)};
  const auto s2{generate_public_key(B, A)};

  // The secret
  const std::string plaintext{"A few questions that I need to know. How"
                              " you could ever hurt me so. I need to kn"
                              "ow what I've done wrong. And how long it"
                              "'s been going on.                       "
                              " llllllllllllllllllllllllllllllllllllll "
                              "lllllllllll  lll  llll  llll   lllllllll"
                              "llllllllll  lll  lllllllllll  llllllllll"
                              "lllllllll       llll  lllll  lllllllllll"
                              "llllllll  lll  llll  lllllllllllllllllll"
                              "lllllll  lll  llll  lllll  lllllllllllll"
                              " llllllllllllllllllllllllllllllllllllll "
                              "Beautiful is better than ugly. Explicit "
                              "is better than implicit. Simple is bette"
                              "r than complex. Complex is better than c"
                              "omplicated. Flat is better than nested. "};

  // Format the message for printing
  const auto format = [](const std::string in) {
    std::stringstream out;

    unsigned n{0};
    for (const auto c : in)
      out << std::hex << std::setw(2) << std::setfill('.') << unsigned(c)
          << (++n % 40 ? "" : "\n");

    return out.str();
  };

  // Encrypt a message using supplied function
  const auto encrypt = [](const auto message, const auto func) {
    return func(message);
  };

  // Convert large numbers back into the printable ASCII range
  const auto wrap_ascii = [](const unsigned i) { return char(i % 0b10000000); };

  // assert(s1 == s2);
  std::cout << A << " Alice's public key\n";
  std::cout << B << " Bill's public key\n";
  std::cout << s1 << " Alice's secret key\n";
  std::cout << s2 << " Bill's secret key\n";

  const auto alg2 = [&wrap_ascii](const std::string message) {
    auto ciphertext = message;
    for (auto &c : ciphertext)
      c = wrap_ascii(c + 1ul);

    return ciphertext;
  };

  const auto alg3 = [&wrap_ascii](const std::string message) {
    auto ciphertext = message;
    auto n{1ul};
    for (auto &c : ciphertext)
      c = wrap_ascii(c + n++);

    return ciphertext;
  };

  const auto alg4 = [&wrap_ascii](const std::string message) {
    auto previous{0ul};
    auto ciphertext = message;
    for (auto &c : ciphertext) {
      c = wrap_ascii(c + 1ul + previous);
      previous = c;
    }

    return ciphertext;
  };

  const auto mod1 = [&wrap_ascii](const std::string message) {
    auto ciphertext = message;
    for (auto &c : ciphertext)
      c = wrap_ascii(std::fmod(std::exp2(unsigned(c)), 127));

    return ciphertext;
  };

  // Decrypt

  const auto alg5 = [&wrap_ascii](const std::string message) {
    auto ciphertext = message;
    for (auto &c : ciphertext)
      c = wrap_ascii(c - 1ul);

    return ciphertext;
  };

  const auto alg6 = [&wrap_ascii](const std::string message) {
    auto plain = message;
    unsigned count{1ul};
    for (auto &c : plain)
      c = wrap_ascii(c - count++);

    return plain;
  };

  const auto alg7 = [&wrap_ascii](const std::string message) {
    auto previous{0ul};
    auto ciphertext = message;
    for (auto &c : ciphertext) {
      c = wrap_ascii(c - 1ul - previous);
      previous = c;
    }

    return ciphertext;
  };

  std::cout << "\n--- plaintext\n" << format(plaintext);
  std::cout << "\n--- rotate\n" << format(encrypt(plaintext, alg2));
  std::cout << "\n--- key schedule\n" << format(encrypt(plaintext, alg3));
  std::cout << "\n--- add previous\n" << format(encrypt(plaintext, alg4));

  std::cout << "\n--- decrypt\n"
            << format(encrypt(encrypt(plaintext, alg4), alg7));

  std::cout << "\n--- plaintext\n" << format(plaintext);
  std::cout << "\n--- mod exp\n" << format(encrypt(plaintext, mod1));

  assert(plaintext == encrypt(encrypt(plaintext, alg2), alg5));
  assert(plaintext == encrypt(encrypt(plaintext, alg3), alg6));
  // assert(plaintext == encrypt(encrypt(plaintext, alg4), alg7));
}
