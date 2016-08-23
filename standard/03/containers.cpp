#include <iostream>

// Sequence containers
#include <vector>
#include <deque>
#include <list>

// Associative containers
#include <map>
#include <set>

// Container adapters
#include <queue>
#include <stack>

int main() {

	using namespace std;
	cout << "Containers" << endl;

	// Sequence containers
	string str("blah");
	cout << "String size " << str.size() << endl;

	vector<int> v = {1, 2, 3, 4}; // Contiguous

	deque<int> d; // Double ended queue - non-contiguous
	list<int> l;

	// Associative containers
	map<int, int> m;
	multimap <int, int> mm;

	set<int, int> s;
	multiset <int, int> ms;

	// Container adapters
	queue<int> q;
	priority_queue<int> pq;
	stack<int> st;

	return 0;
}
