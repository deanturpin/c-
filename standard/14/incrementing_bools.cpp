#include <iostream>

int main() {

	using namespace std;

	bool once = false;

	while (!once++)
		cout << "Hello" << endl;

	return 0;
}
