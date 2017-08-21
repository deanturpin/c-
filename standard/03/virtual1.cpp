#include <iostream>

class base {
	public:
		virtual ~base() {}
		virtual void blah() { std::cout << "base" << std::endl; }
};

class derived : base {
	public:
		~derived() {}
		void blah() { std::cout << "derived" << std::endl; }
};

int main() {

	base b;
	derived d;

	b.blah();
	d.blah();
}
