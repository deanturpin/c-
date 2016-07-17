// C++03

#include <iostream>
#include <vector>
#include <deque>
#include <list>

#include <stack>
#include <queue>

// C++11

#include <array>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>

int main()
{
	using namespace std;

	// C++03

	// Basic containers
	vector<int> v; // Contiguous
	deque<int> d;
	list<int> l;

	// Adapters

	stack<int> s;
	queue<int> p;
	priority_queue<int> pq;

	// C++11

	// array<int> a;
	forward_list<int> f;

	unordered_set<int> us;
	unordered_multiset<int> um;
	// unordered_map<int> us;
	// unordered_multimap<int> um;

	return 0;
}
