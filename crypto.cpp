#include <cassert>
#include <cmath>
#include <iostream>

int main() {

  const auto generate_public_key = [](const auto seed,
                                      const auto base) constexpr {
    return std::lrint(std::pow(base, seed)) % 23;
  };

  const auto encrypt = [](const std::string plaintext) {
    auto ciphertext = plaintext;
    return ciphertext;
  };

  // Generate and exchange keys
  const auto a{5ul};
  const auto b{4ul};
  const auto A{generate_public_key(a, 5)};
  const auto B{generate_public_key(b, 5)};
  const auto s1{generate_public_key(A, B)};
  const auto s2{generate_public_key(B, A)};

  // The secret
  const std::string plaintext{R"(
llllllllllllllllllllllllllllllllllllllll
lllllllaaaaaaaaaaaaaaaaaaallllllllllllll
lllllllaaaaaaaaaaaaaaaaaaallllllllllllll
llllllllllllllalllllllllllllllllllllllll
lllllllllllllllallllllllllllllllllllllll
llllllllllllllllalllllllllllllllllllllll
lllllllllllllllllallllllllllllllllllllll
llllllllllllllllllalllllllllllllllllllll
lllllllllllllllllllallllllllllllllllllll
llllllllllllllllllllalllllllllllllllllll
lllllllllllllllllllllallllllllllllllllll
llllllllllllllllllllllalllllllllllllllll
lllllllllllllllllllllllallllllllllllllll
llllllllllllllllllllllllalllllllllllllll
lllllllllllllllllllllllllallllllllllllll
llllllllllllllllllllllllllalllllllllllll
lllllllllllllllllllllllllllallllllllllll
llllllllllllllllllllllllllllalllllllllll
llllllllllllllllllllllllllllllllllllllll
)"};

  // Encrypt the secret
  const auto ciphertext = encrypt(plaintext);

  // assert(s1 == s2);
  std::cout << A << " Alice's public key\n";
  std::cout << B << " Bill's public key\n";
  std::cout << s1 << " Alice's secret key\n";
  std::cout << s2 << " Bill's secret key\n";
  std::cout << plaintext;
  std::cout << ciphertext;
}
