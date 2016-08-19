#include <string>
#include <iostream>

namespace aml {

	using namespace std;

	class animal {

		// private:
			// int legs;
			// bool fur;
			string myName;
		public:
			animal() : myName("animal") {
				cout << "My name is " << myName << endl;
			}

			~animal() {
				cout << "Goodbye " << myName << endl;
			}

	};

	class squirrel : public animal {
		public:
		squirrel() {
			myName = "squirrel";
		}
		// string myName;
	};

	/*
	class goat : public animal {
	};

	class lizard : public animal {
	};
	*/

#if 0
	class animalFactory {
		public:

			animal* createAnimal() {
				return new squirrel;
			}
	};
#endif
}

int main() {

	// Factory
	// aml::animalFactory fac;
	// aml::animal* a = fac.createAnimal();

	aml::animal* a = new aml::animal();
	delete a;

	aml::animal* s = new aml::squirrel();
	delete s;

	return 0;
}
