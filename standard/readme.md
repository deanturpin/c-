# Containers
_Sequence containers_

array 
vector
deque
forward_list 
list

_Container adapters_

stack
queue
priority_queue

_Associative containers (ordered)_

set multiset map multimap 

_Associative containers (unordered)_

unordered_set unordered_multiset unordered_map unordered_multimap

# Keywords
static_cast reinterpret_cast dynamic_cast const_cast

using(1) namespace

struct class union friend

private protected public 

inline mutable operator virtual explicit 

switch case break default(1) continue

catch throw try

typedef typeid typename

true false

while for if do else

new delete(1)

unsigned signed const long

auto(1) void bool char wchar_t float double short int

xor xor_eq and and_eq bitand bitor not not_eq or or_eq compl

export(1) extern static

volatile register 

sizeof this template asm enum goto return

_C++11_

decltype constexpr lignas alignof char16_t char32_t static_assert thread_local nullptr noexcept override final

_Concepts TS_

requires concept

#Issues
- Data races, deadlocks and livelocks - unsynchonised access to shared memory can introduce race conditions and undefined behaviour (program results depend nondeterministcially on the relative timings of two or more threads)
- Threads versus processes
- Too few threads - alogorithm is sub-optimal
- Too many threads - overhead of creating/managing and partitioning the data is greater than processing advantage; software threads outnumber the available hardware threads and the OS must intervene
