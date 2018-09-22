#include <iostream>
#include <regex>

int main() {

  using namespace std;

  string search("blah yes blah no");
  regex expression("blah");

  if (regex_match(search, expression))
    cout << "Match yes" << ' '; else cout << "Match no" << '
';

        // mark_count()

        return 0;
}

/*
#include <iostream>
#include <regex>

int main()
{
        using namespace std;

        // Read complete file on stdin
        stringstream raw;
        raw << cin.rdbuf();
        const string hosts = raw.str();

        // const regex word_regex(R"((?:[0-9]{1,3}\.?){4}\s+\S+)");
        const regex word_regex("blah");

        const auto words_begin = sregex_iterator(hosts.cbegin(), hosts.cend(),
word_regex);

        cout << "Found " << distance(words_begin, sregex_iterator()) << '
';

        for (std::sregex_iterator i = words_begin; i != sregex_iterator(); ++i)
                cout << R"(")" << i->str() << R"(")" << '
';

        return 0;
}
*/
