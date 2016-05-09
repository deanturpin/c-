#include <iostream>
#include <regex>

void regular_expressions() {

	using namespace std;

	string search("blah yes blah no");
	regex expression("blah");

	if (regex_match(search, expression))
		cout << "Match yes" << endl;
	else
		cout << "Match no" << endl;

	// mark_count()
}
