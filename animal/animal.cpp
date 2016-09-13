#include<iostream>

namespace pet {
	using namespace std;

	class animal;
	class dog;

	class animal {

		const string name = "animal";

		public:

			animal() { cout << "+ " << name << endl; }
			~animal() { cout << "- " << name << endl; }

			// explicit
			// animal(const int l) : legs(l) { }
			// animal() { }

			void print() { cout << "\tanimal" << endl; }
	};

	/*

	class dog : public animal {

		public:

			// dog(const int l) { }
			dog() { cout << "+ dog" << endl; }
			~dog() { cout << "- dog" << endl; }

			void print() { cout << "\tdog" << endl; }
	};
	*/
}

int main() {

	// pet::animal a(2);
	pet::animal a;
	a.print();

	// pet::dog d;
	// d.print();

	return 0;
}
