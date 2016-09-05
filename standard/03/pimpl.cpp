// compiler firewall
// handle body pattern

// separate implementation from interface
// change implementation without need to recompile
// - include header file and header file has changed

#include <iostream>

namespace wrk {

	using namespace std;

	class Employee {

		string name;

		public:

		string getName() {

			return name;
		}

		void setName(const string &n) {

			name = n;
		}
	};
}

int main() {

	using namespace std;

	wrk::Employee e;
	e.setName("blah");

	cout << "Name is " << e.getName() << endl;

	return 0;
}
