#include <iostream>
#include <vector>

namespace bigo {

	using namespace std;

	void heading(const string &);
	void constant();
	void linear();
	void square();
	void exponential();
	void logarithmic();

	// Common heading
	void heading(const string &name) {

		cout << name << endl;
		cout << "----------" << endl;
	}

	void constant() {

		heading("Constant\tO(1)");
	}

	void linear() {

		heading("Linear\t\tO(N)");

		vector<int> vec(10000, 0);
		for (auto &i: vec)
			++i;
	}

	void square() {

		heading("Square\t\tO(N^2)");

		vector<int> vec(10000, 0);
		for (auto &i: vec)
			++i;
	}

	void exponential() {

		heading("Exponential\tO(2^N)");
	}

	void logarithmic() {

		heading("Logarithmic\tO(log N)");
	}
}

int main() {

	using namespace std;

	bigo::constant();
	bigo::linear();
	bigo::square();
	bigo::exponential();
	bigo::logarithmic();

	return 0;
}
