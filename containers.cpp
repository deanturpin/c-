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

  //////////
  // Sequence containers

  // String
  std::string str(10, 'x');
  std::cout << "std::string size " << str.size() << '\n';

  // Vector
  //	- contiguous
  //	- no push_front()
  std::vector<int> v = {1, 2, 3, 4};
  v.push_back(5);
  v.pop_back();
  std::cout << "vector size " << v.size() << '\n';

  // Double ended queue
  //	- non-contiguous
  std::deque<int> d = {1, 2, 3, 4};
  d.push_front(0);
  d.push_back(5);
  d.pop_front();
  d.pop_back();
  std::cout << "deque size " << d.size() << '\n';

  // List
  std::list<int> l = {1, 2, 3, 4};
  l.push_front(0);
  l.push_back(5);
  l.pop_front();
  l.pop_back();
  std::cout << "list size " << l.size() << '\n';

  //////////
  // Associative containers

  // Maps
  std::map<int, int> m;
  m.emplace(std::make_pair(0, 1));
  m.emplace(std::make_pair(0, 2));
  m.emplace(std::make_pair(0, 3));
  std::cout << "map size " << m.size() << '\n';
  for (const auto &_m : m)
    std::cout << "\t" << _m.first << ", " << _m.second << '\n';

  std::multimap<int, int> mm;
  mm.emplace(std::make_pair(0, 1));
  mm.emplace(std::make_pair(0, 2));
  mm.emplace(std::make_pair(0, 3));
  std::cout << "multimap size " << mm.size() << '\n';
  for (const auto &_m : mm)
    std::cout << "\t" << _m.first << ", " << _m.second << '\n';

  // Sets
  std::set<int> s = {1, 2, 3, 4, 4, 4, 4};
  std::cout << "set size " << s.size() << '\n';
  for (const auto &_s : s)
    std::cout << "\t" << _s << '\n';

  std::multiset<int> ms = {1, 2, 3, 4, 4, 4, 4};
  std::cout << "multiset size " << ms.size() << '\n';
  for (const auto &_s : ms)
    std::cout << "\t" << _s << '\n';

  //////////
  // Container adapters

  const std::deque<int> init = {1, 0, 3, 2, 2, 5, 6, 7};

  // Queue
  std::queue<int> q(init);
  std::cout << "queue size " << q.size() << '\n';
  while (!q.empty()) {
    std::cout << "\t" << q.front() << '\n';
    q.pop();
  }

  // Priority queue
  std::priority_queue<int> pq;
  pq.emplace(1);
  pq.emplace(0);
  pq.emplace(3);
  pq.emplace(2);
  std::cout << "priority_queue size " << pq.size() << '\n';
  while (!pq.empty()) {
    std::cout << "\t" << pq.top() << '\n';
    pq.pop();
  }

  // Stack
  std::stack<int> st(init);
  std::cout << "stack size " << st.size() << '\n';
  while (!st.empty()) {
    std::cout << "\t" << st.top() << '\n';
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
