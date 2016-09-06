#include <iostream>
#include <fstream>

int main() {

	using namespace std;

	cout << "Random noise" << endl;

	const string randomFile = "/dev/urandom";
	cout << "Using " << randomFile << endl;

	// stringstream oui;
	int blah;
	auto is = ifstream(randomFile);
	is.read(reinterpret_cast<char *>(&blah), sizeof blah);

	cout << "Read " << blah << endl;

	return 0;
}
