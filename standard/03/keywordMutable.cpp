int main()
{
	struct A {
		// Variable is increment despite being a const method
		void constMemberFunction() const { ++m; }
		mutable int m;
	};

	A a;
	a.constMemberFunction(); 

	return 0;
}
