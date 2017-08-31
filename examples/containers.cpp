#include <iostream>

// Sequence containers
#include <deque>
#include <list>
#include <vector>

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

  const deque<int> init = {1, 0, 3, 2, 2, 5, 6, 7};

  // Queue
  queue<int> q(init);
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
  stack<int> st(init);
  cout << "stack size " << st.size() << endl;
  while (!st.empty()) {
    cout << "\t" << st.top() << endl;
    st.pop();
  }

  // array<int, 10> a;
  // forward_list<int> f;
  // unordered_set<int> us;
  // unordered_multiset<int> um;
  // unordered_map<int> us;
  // unordered_multimap<int> um;

  return 0;
}
