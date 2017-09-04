# Recursion
TBD

# Big-O notation

Is a technique to describe the complexity of an algorithm as the data set
becomes larger.

- [Big-O Notation](https://github.com/deanturpin/Big-O-Notation)
- [Big-O cheat sheet](http://bigocheatsheet.com/).
- [Sort animations](http://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html)

One last thing is be prepared to write code. We often asked candidates to write a container type or sort algo on a whiteboard or piece of paper. So remember your merge sort, quick sort, binary search, etc, and be able to write them cold.


## Sorting algorithms
- Selection sort
- Insertion sort
- Quick sort (LR pointers)
- Merge sort O(n log n)`
- Tree sort
- Tim sort O(n log n)
- Heap sort
- Radix sort (LSD)
- Radix sort (MSD)
- std::sort (gcc)
- std::stable_sort (gcc)
- Shell sort
- Cocktail shaker sort
- Gnome sort
- Bitonic sort
- Bogo sort

```
Algorithm	Time Complexity	Space Complexity
Best	Average	Worst	Worst
Quicksort	Ω(n log(n))	Θ(n log(n))	O(n^2)	O(log(n))
Mergesort	Ω(n log(n))	Θ(n log(n))	O(n log(n))	O(n)
Timsort	Ω(n)	Θ(n log(n))	O(n log(n))	O(n)
Heapsort	Ω(n log(n))	Θ(n log(n))	O(n log(n))	O(1)
Bubble Sort	Ω(n)	Θ(n^2)	O(n^2)	O(1)
Insertion Sort	Ω(n)	Θ(n^2)	O(n^2)	O(1)
Selection Sort	Ω(n^2)	Θ(n^2)	O(n^2)	O(1)
Tree Sort	Ω(n log(n))	Θ(n log(n))	O(n^2)	O(n)
Shell Sort	Ω(n log(n))	Θ(n(log(n))^2)	O(n(log(n))^2)	O(1)
Bucket Sort	Ω(n+k)	Θ(n+k)	O(n^2)	O(n)
Radix Sort	Ω(nk)	Θ(nk)	O(nk)	O(n+k)
Counting Sort	Ω(n+k)	Θ(n+k)	O(n+k)	O(k)
Cubesort	Ω(n)	Θ(n log(n))	O(n log(n))	O(n)

```

## Considerations
- Size of input
- Type of input (partially sorted, random)

## Examples
### Bubble sort

