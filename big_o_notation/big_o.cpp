#include <iostream>
#include <vector>

namespace bigo
{
	using namespace std;

	// Common heading
	void heading(const std::string &name)
	{
		cout << name << endl;
		cout << "----------" << endl;
	}

	// Constant 
	void constant()
	{
		heading("Constant\tO(1)");
		cout << "Vector index" << endl;
		vector<int> vec(10000, 0);
		for (auto &i: vec)
			++i;
	}
}

int main() {

	using namespace std;

	bigo::constant();
	bigo::heading("Linear\t\tO(N)");
	bigo::heading("Square\t\tO(N^2)");
	bigo::heading("Exponential\tO(2^N)");
	bigo::heading("Logarithm\tO(log N)");

	return 0;
}
