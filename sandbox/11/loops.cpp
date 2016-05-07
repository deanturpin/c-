#include <iostream>
#include <vector>

void loops()
{
	using namespace std;

	vector<int> vec = {1, 2, 3,};

	// For each
	for (const auto &v : vec)
		cout << "cont " << v << endl;

	for (const auto &i : {5, 4, 3})
		cout << "iter " << i << endl;
}
