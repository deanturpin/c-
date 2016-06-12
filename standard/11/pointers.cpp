#include <iostream>
#include <string>
#include <memory>

namespace wood
{
	using namespace std;

	class Animal
	{
		public:
			Animal() : name("default")
				{ cout << "Animal ctor" << endl; }

			~Animal() { cout << "Animal dtor" << endl; }

			string name;
	};
}

void pointers()
{
	using namespace std;
	using namespace wood;

	auto a = unique_ptr<Animal>(new Animal);
	cout << "name " << a->name << endl;

	// Using reset
	unique_ptr<Animal> b;
	b.reset(new Animal);
	b.reset();
}
