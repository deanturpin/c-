// 
// * Explain constructor/destructor ordering
// * Describe move constructors
// 
// * = default 
// * explicit
// 
// Gold rule is to use explicit keyword for all constructors which can be called with one argument provided unless you want to enable implicit conversion from argument type.
// 
// ## Aggregate class
// * Can be initialised with a brace-enclosed comma-separated list of initialiser clauses
// 
// ## POD structs
// * Same memory layout as struct declared in C
// 
// # Operators
// * ```operator[]```
// * rel_ops
// 
// ## Difference between a class and a struct?

// In C++, a class defined with the class keyword has private members and base
// classes by default. A structure is a class defined with the struct keyword.[1]
// Its members and base classes are public by default. This is the only difference
// between structs and classes in C++.
// 
// # Constructors
// ## Copy
// ## Move
// ## Destructor
// ## Copy assignment
// ## Move assignment
// ## Default/deleted constructors
// See [CPP Reference](http://en.cppreference.com/w/cpp/language/default_constructor).
// 
// deleting NULL pointers have no effect.  deleting a pointer to a base class
// which points to a derived object is legal assuming the base destructor is
// virtual. deleting an array of objects using a base class pointer is undefined.
// 
// ## References
// * https://en.wikipedia.org/wiki/C%2B%2B_classes
// 
// Initialisation follow member declaration order not the initialiser order: do
// not use data members in initialiser expressions.
// 
// Default arguments can lead to unintended calls

class a {

	public:
	a() = default;
	a(int) = delete;
};

int main() {

	// Constructor
	a a1;

	// Copy constructor
	a a2(a1);

	// Assignment constructor
	a a3 = a1;

	// Error - call to deleted constructor
	// a a4(1);

	return 0;
}

