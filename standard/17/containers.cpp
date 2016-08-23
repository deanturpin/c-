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

	//////////
	// Sequence containers

	// String
	string str(10, 'x');
	cout << "string size " << str.size() << endl;

	// Vector
	//	- contiguous
	//	- no push_front()
	vector<int> v = {1, 2, 3, 4};
	v.push_back(5);
	v.pop_back();
	cout << "vector size " << v.size() << endl;

	// Double ended queue
	//	- non-contiguous
	deque<int> d = {1, 2, 3, 4};
	d.push_front(0);
	d.push_back(5);
	d.pop_front();
	d.pop_back();
	cout << "deque size " << d.size() << endl;

	// List
	list<int> l = {1, 2, 3, 4};
	l.push_front(0);
	l.push_back(5);
	l.pop_front();
	l.pop_back();
	cout << "list size " << l.size() << endl;

	//////////
	// Associative containers

	// Maps
	map<int, int> m;
	m.emplace(make_pair(0, 1));
	m.emplace(make_pair(0, 2));
	m.emplace(make_pair(0, 3));
	cout << "map size " << m.size() << endl;
	for (const auto &_m : m)
		cout << "\t" << _m.first << ", " << _m.second << endl;

	multimap<int, int> mm;
	mm.emplace(make_pair(0, 1));
	mm.emplace(make_pair(0, 2));
	mm.emplace(make_pair(0, 3));
	cout << "multimap size " << mm.size() << endl;
	for (const auto &_m : mm)
		cout << "\t" << _m.first << ", " << _m.second << endl;

	// Sets
	set<int> s = {1, 2, 3, 4, 4, 4, 4};
	cout << "set size " << s.size() << endl;
	for (const auto &_s : s)
		cout << "\t" << _s << endl;

	multiset<int> ms = {1, 2, 3, 4, 4, 4, 4};
	cout << "multiset size " << ms.size() << endl;
	for (const auto &_s : ms)
		cout << "\t" << _s << endl;

	//////////
	// Container adapters

	// Queue
	queue<int> q;
	q.emplace(1);
	q.emplace(0);
	q.emplace(3);
	q.emplace(2);
	cout << "queue size " << q.size() << endl;
	while (!q.empty()) {
		cout << "\t" << q.front() << endl;
		q.pop();
	}

	// Priority queue
	priority_queue<int> pq;
	pq.emplace(1);
	pq.emplace(0);
	pq.emplace(3);
	pq.emplace(2);
	cout << "priority_queue size " << pq.size() << endl;
	while (!pq.empty()) {
		cout << "\t" << pq.top() << endl;
		pq.pop();
	}

	// Stack
	stack<int> st;
	st.emplace(1);
	st.emplace(0);
	st.emplace(3);
	st.emplace(2);
	cout << "stack size " << st.size() << endl;
	while (!st.empty()) {
		cout << "\t" << st.top() << endl;
		st.pop();
	}

	return 0;
}