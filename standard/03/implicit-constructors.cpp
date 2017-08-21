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
