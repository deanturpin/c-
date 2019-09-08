#include <string>
#include <iostream>

const std::string regex{R"(
^                                             # start of string
(                                             # first group start
  (?:
    (?:[^?+*{}()[\]\\|]+                      # literals and ^, $
     | \\.                                    # escaped characters
     | \[ (?: \^?\\. | \^[^\\] | [^\\^] )     # character classes
          (?: [^\]\\]+ | \\. )* \]
     | \( (?:\?[:=!]|\?<[=!]|\?>)? (?1)?? \)  # parenthesis, with recursive content
     | \(\? (?:R|[+-]?\d+) \)                 # recursive matching
     )
    (?: (?:[?+*]|\{\d+(?:,\d*)?\}) [?+]? )?   # quantifiers
  | \|                                        # alternative
  )*                                          # repeat content
)                                             # end first group
$   
)"};


int main() {
	std::cout << regex << "\n";
}
