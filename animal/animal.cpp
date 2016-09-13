#include<iostream>

namespace pet {
	using namespace std;

	class animal;
	class dog;

	class animal {


		const int legs;

		public:
			animal(const int l) : legs(l) { }
			void print() {
				cout << "legs " << legs << endl;
			}
	};

	class dog : public animal {
	};
}

int main() {

	pet::animal a(2);
	a.print();

	return 0;
}
