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

	auto a = unique_ptr<wood::Animal>(new wood::Animal);
	cout << "name " << a->name << endl;
}
