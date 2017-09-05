   Multi-threaded concepts are going to be very important. Atomics, locks,
   issues with different designs, how to make things thread safe. Cache
   locality is another huge thing these days. What is cache locality- how do
   multicore systems ensure their cache's are in sync? How do you get around
   this problem? Asynchronous architectures and callbacks are what you will be
   dealing with every day. Why are signals slow and why is context switching
   bad? What exactly happens during a context switch?

# Issues
- Data races, deadlocks and livelocks - unsynchonised access to shared memory can introduce race conditions and undefined behaviour (program results depend nondeterministcially on the relative timings of two or more threads)
- Threads versus processes
- Too few threads - alogorithm is sub-optimal
- Too many threads - overhead of creating/managing and partitioning the data is greater than processing advantage; software threads outnumber the available hardware threads and the OS must intervene

# Race condition
An unfortunate order of execution causes undesirable behaviour.

* multi-threading & mutexes
* Deadlocks, threads, deadlock prevention

# Mutex
std::mutex or std::atomic

# Threads
A thread is a branch of execution.

- Immutability is great for multi-threading. Functional programming works well
- concurrently partly due to the emphasis on immutability.
- Use locks when you access mutable shared data, both for reads and writes.
- Don't try to go lock-free unless you really have to. Locks are expensive, but rarely the bottleneck.
- Monitor.Wait should almost always be part of a condition loop, waiting for a condition to become true and waiting again if it's not.
- Try to avoid holding locks for longer than you need to.
- If you ever need to acquire two locks at once, document the ordering thoroughly and make sure you always use the same order.
- Document the thread-safety of your types. Most types don't need to be thread-safe, they just need to not be thread hostile (i.e. "you can use them from multiple threads, but it's your responsible for taking out locks if you want to share them)
- Don't access the UI (except in documented thread-safe ways) from a non-UI thread. In Windows Forms, use Control.Invoke/BeginInvoke
- Try to avoid calling out to external code while holding a lock



# Threads and operating systems

- POSIX Threads evaluates understanding of basic thread management, user versus
  kernel threads and thread attributes

- Thread Synchronization measures the ability to create and use mutexes,
  semaphores, condition variables, and signal handling with threads

- Ethernet and TCP/IP Protocols and Architecture tests familiarity with 802 3,
  Internet Protocol (IP), ARP, Internet Addressing and basic Ethernet oriented
  LAN internetworking hardware (bridges and routers)

- Functions measures understanding of the different ways of calling functions in
  ANSI C and when to use each

- Memory Allocation assesses and tests understanding of static and dynamic
  memory allocation in ANSI C, and practical uses of each; measures
  understanding of memory-allocation hazards such as memory leaks

- Structures and Unions evaluates understanding of structures and unions in ANSI
  C programming; measures knowledge of issues such as the combination of
  declaration and definition, the alignment of structure and union elements, the
  passing of structure variables by value and by address, and the usage of
  structure operators

- Data Types assesses and tests general knowledge of ANSI C data types, the
  subtle variations in their use and their effect on memory consumed

- Pointers evaluates understanding of using of pointers in ANSI C programming,
  their different forms, and the common pitfalls in their usage

- Bitwise Operators assesses understanding of the ANSI C bitwise operators

- C Language Syntax checks whether or not a person knows the C guidelines to
  code a program and can recognize syntax errors

- Operators tests proficiency in using ANSI C arithmetic, logical, relational,
  conditional, and compound assignment operators

- Function Pointers measures understanding of the setup and use of pointers to
  functions in ANSI C, such as in callback mechanisms

- Performance Monitoring and Tuning checks understanding of Unix
  performance-related concepts (including CPU, memory, I/O) and the Unix
  utilities, such as vmstat, iostat, ps, top, sar, dd, uptime and ipcs used to
  address performance issues

## Out of scope
- Controlling Processes determines the ability to create child processes and use
  such functions as fork, vfork, exit, wait and waitpid and exec

- Tests understanding of how calling conventions work and their effect on the
  arguments passed to a function

- Real-Time Programming measures proficiency in using ANSI C to develop
  timing-sensitive embedded software and firmware, running in and out of
  interrupt service routines

- Interfacing with Hardware assesses proficiency in using ANSI C to manipulate
  hardware devices connected to a microprocessor or microcontroller in an
  embedded system, typically accessed via addresses in memory space

- Interprocess Communications tests knowledge of pipes, message queues,
  semaphores, shared memory, and System V IPC

