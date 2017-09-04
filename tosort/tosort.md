# Monday
* https://en.wikipedia.org/wiki/C%2B%2B_classes
* https://en.wikipedia.org/wiki/C%2B%2B11#Modification_to_the_definition_of_plain_old_data
* https://en.wikipedia.org/wiki/Return_value_optimization
* http://www.gamedev.net/community/forums/topic.asp?topic_id=553197
* http://www2.research.att.com/~bs/
* http://www.parashift.com/c++-faq-lite/
* http://yosefk.com/c++fqa/
* https://en.wikipedia.org/wiki/ROLI

# From the ROLI coding standard
* JUCE
* If you override a virtual method in a sub-class, ALWAYS mark it with the new C++11 override specifier, and NEVER write it with a redundant virtual keyword!
* If a method definitely doesn't throw an exception (be careful!), mark it asnoexcept. This can have a dramatic effect on performance in some situations - apparently up to 10x in extreme cases.
* When returning a temporary object, e.g. a String, the returned object should be non-const, so that if the class has a C++11 move operator, it can be used.
* When you're testing a pointer to see if it's null, never write "if (myPointer)". Always avoid that implicit cast-to-bool by writing it more fully: "if (myPointer != nullptr)". And likewise, never ever write "if (! myPointer)", instead always write "if (myPointer == nullptr)". I find it much more readable like that.
* copy-by-value semantics
* Constructors that take a single parameter should be default be marked 'explicit'.
* null NULL 0 nullptr
* ```if(Foo* f = getFoo())``` - newer C++?
Always stick to pass-by-value if possible, and only use references if the price of calling the copy constructor is very high.


* [Placement new](http://www.devx.com/tips/Tip/12582)
* Data structure performance (cache local = important)
* perfect forwarding
* the well known example with pass-by-copy but with pointers
* in the code snipper make sure there are no memory leaks

* C++11, get a really good grasp of what r-value, x-value, l-value are & what std::move/std::forward really do. This is probably the most difficult topic to truly understand at an expert level, but a workable understanding is possible.
* C++11: & and && specifiers on functions.
* C++14: decltype(auto) vs auto
* C++11: auto vs const auto vs const auto& vs auto&&.
* General: thread-safety, general concurrency topics, atomics & when they might be useful etc.
* General: why should you prefer composition over inheritance? why should you restrict inheritance to pure-virtual interfaces.
* C++11: what does override do & why is it necessary?
* C++11: what does final do & how why is it important for compiler optimizations
* C++11: variadic templates & universal references
* C++11: write a perfect-forwarding function (e.g. make_unique).
* C++11: constexpr - when does it not work as you might expect? i.e. why is
* constexpr int foo() { throw std::runtime_error(); };
* int main() { foo(); }
* a runtime error instead of a compile error

* decltype(auto), auto, auto&&, const auto&, T&& 

# Type traits
TODO

# offsetof
* https://en.wikipedia.org/wiki/Offsetof

# Andrew's tips
- It may be different for you but they didn't ask me any Linux stuff only c c++
- how we use agile
- design patterns we use
- constructors, virtual destructors, copy constructors
- Basics of OO abstraction encapsulation inheritance etc operator/function
  overloading new/delete malloc.

For the design patterns stuff don't forget you use active objects every day
which is a valid design pattern + class factories etc. They didn't expect me to
be an expert on design patterns just to know what we use. Same with agile. They
may anticipate me telling you all this and change the questions of course

- C++ Multi-Threading Library assesses the understanding of the concepts and
issues of multi-threading and the proper implementation using the C++ Threading
support library

Polymorphism determines proficiency in implementing polymorphism in C++ with the
use of virtual functions including dynamic casting and RTTI.
https://www.cs.bu.edu/teaching/cpp/polymorphism/intro/

Dynamic Memory Allocation determines understanding of dynamic memory support
provided by the C++ Standard Library.
http://en.cppreference.com/w/cpp/memory

Pointers evaluates understanding of using of pointers in ANSI C programming,
their different forms, and the common pitfalls in their usage.

Inheritance assesses proficiency in the use of inheritance in C++ as a tool for
the reuse, extension and modification of existing types including inheritance
access control and multiple inheritance.

Class Access Control measures understanding of C++ class access including access
levels, base class member access, access modification and friends.

Object-Oriented Concepts tests the awareness about concepts distinguishing OOP
from other paradigms.

C++ Types measures understanding of basic C++ types and the rules for their
declaration and use.

Overloading assesses knowledge of C++ function and operator overloading. Class
Creation and Usage evaluates proficiency with user-defined types in C++
(including structures) -- definition, declaration and usage.

C++ Basic Concepts evaluates the basic understanding of writing a C++ program.
Also covers lambda functions.

Bitwise Operators assesses understanding of the different bitwise operators and
their utility in ANSI C programming.

Function Pointers measures understanding of the setup and use of pointers to
functions in ANSI C, such as in callback mechanisms.
